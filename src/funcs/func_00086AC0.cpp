struct Vector3 {
    float x;
    float y;
    float z;
};

// An axis and an angle (func_001BAC70 reads the angle at 0xc).
struct Rotation_000D2B90 {
    Vector3 axis;
    int angle;
};

// The motion values (0x20DA90 for the kind at 0x1CD210): two factors, the fall per frame and the most it turns in
// one frame.
struct Motion_00086D30 {
    float scale;
    float lift;
    float step;
    int turn;
};

// A player (object 4 and on): its position at +0xca4.
struct Object_000A1C50 {
    char unknown_0000[0xca4];
    Vector3 position;
};

struct Node {
    virtual ~Node();

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

// The family of tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210 (constructor 0x862B0, destructor 0x86460).
struct Object_00086960 : Node {
    Vector3 start;
    Vector3 position;
    Vector3 direction;
    char unknown_068[0xc];
    float scale;
    float lift;
    char unknown_07c[0x2c];
    unsigned int frames;
    Motion_00086D30 *motion;
    char unknown_0b0[0xa8];
    int target;
    int following;
    int rising;

    void func_00086AC0(Object_000A1C50 *object);
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC70(Rotation_000D2B90 *rotation);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
void __fastcall func_0014C500(Vector3 *vector, const Vector3 *other);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);
int func_0014C7A0(float cosine);
float func_0014C7F0(float value);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);

// Steers at the player while it follows one (func_00086FA0). Once it has stopped rising (+0x160 clear) it turns the
// direction towards the point 15 above the player's position, by at most the motion's turn per call (about the
// cross product of the two; func_001BAC70, func_001BAC00), and moves along it by the scale (func_0014C730). While it
// rises it turns in the flat (y 0) towards the player, all the way round when the player is right behind, moves
// along the direction by the scale and up by the lift, takes the motion's fall off the lift and stops rising once
// the lift is spent.
void Object_00086960::func_00086AC0(Object_000A1C50 *object)
{
    Vector3 way;
    Rotation_000D2B90 rotation;
    if (!rising) {
        way = object->position;
        way.y += 15.0f;
        func_0014C500(&way, &start);
        if (func_0014C460(&way, &way) > 0.0f) {
            float cosine = func_0014C800(&way, &direction);
            if (func_0014C7F0(cosine) < 0.999f) {
                func_0014C3B0(&rotation.axis, &direction, &way);
                func_0014C410(&rotation.axis, &rotation.axis);
                int angle = func_0014C7A0(cosine) & 0xffff;
                int turn = motion->turn;
                if ((short)angle > turn) {
                    rotation.angle = motion->turn;
                } else {
                    rotation.angle = (short)angle < -motion->turn ? -motion->turn : angle;
                }
                func_001BA9C0();
                func_001BAC70(&rotation);
                func_001BAC00(&direction, &direction);
                func_001BAA50();
            }
        }
        func_0014C730(&position, &direction, scale);
    } else {
        func_0014C4C0(&way, &object->position, &start);
        way.y = 0.0f;
        if (func_0014C460(&way, &way) > 0.0f) {
            float cosine = func_0014C800(&way, &direction);
            if (func_0014C7F0(cosine) < 0.999f) {
                func_0014C3B0(&rotation.axis, &direction, &way);
                int angle = func_0014C7A0(cosine) & 0xffff;
                if ((short)angle > motion->turn) {
                    rotation.angle = motion->turn;
                } else {
                    rotation.angle = (short)angle < -motion->turn ? -motion->turn : angle;
                }
                func_001BA9C0();
                func_001BAC70(&rotation);
                func_001BAC00(&direction, &direction);
                func_001BAA50();
            } else if (cosine < 0.0f) {
                rotation.axis.x = 0.0f;
                rotation.axis.y = 1.0f;
                rotation.axis.z = 0.0f;
                rotation.angle = motion->turn;
                func_001BA9C0();
                func_001BAC70(&rotation);
                func_001BAC00(&direction, &direction);
                func_001BAA50();
            }
        }
        position.x += direction.x * scale;
        float y = position.y;
        position.z += direction.z * scale;
        position.y = y + lift;
        lift -= motion->step;
        if (lift <= 0.0f) {
            rising = 0;
        }
    }
}
