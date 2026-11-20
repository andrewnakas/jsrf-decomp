/* const: 0x10000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Frame_000C1490 {
    int kind;
    char unknown_04[0x24];
    float scale;
    Vector3 normal;
    Frame_000C1490 *next;
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *direction);
    void func_000C1490(Vector3 *out, Frame_000C1490 *frame, float first, float second);
    void func_000C1DF0(const Vector3 *from, Vector3 *direction);
};

extern Object_00157F10 *data_00257CE8;

// The object at data_00257CE4: its speed at 0xb4 and a point at 0xb8.
struct Object_000C1270 {
    char unknown_00[0xb4];
    float speed;
    Vector3 point;
};

extern Object_000C1270 *data_00257CE4;

void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);

// The owner at 0x4: angles at 0x50, a speed at 0x5c and flags at 0xa4.
struct Owner_000E6590 {
    char unknown_00[0x50];
    Angles_000C1300 angles;
    float speed;
    char unknown_60[0x44];
    unsigned int flags;
};

struct Object_000E6590 {
    int unknown_00;
    Owner_000E6590 *owner;
    char unknown_08[0xc];
    Vector3 position;
    char unknown_20[0x20];
    Vector3 direction;
    char unknown_4c[0x24];
    Frame_000C1490 *frames;

    void func_000E5A90(int argument);
    void func_000E5B20(int argument);
    void func_000E5BC0(int argument);
    void func_000E5C50(int argument);
    void func_000E6590();
};

// Finds the first kind-0 frame of the list at 0x70 and takes its direction at 0x40 (func_000C1490). A flat direction
// that is not zero is normalised; when the object at data_00257CE4 moves faster than 1.39 the owner takes that speed
// and turns by how its facing meets the direction (func_000E5A90 ahead, func_000E5B20 behind, func_000E5BC0 or
// func_000E5C50 to either side), its speed capped at 1.62, and data_00257CE8 aims the point at 0xb8 along it; the
// owner gets flag 0x10000 and loses 0x8000. Otherwise the position moves back along the frame's normal by its
// scale. A flag set by the speed test reproduces retail's block order (the short path inline).
void Object_000E6590::func_000E6590()
{
    for (Frame_000C1490 *frame = frames; frame; frame = frame->next) {
        if (frame->kind == 0) {
            data_00257CE8->func_000C1490(&direction, frame, 0.0f, 1.0f);
            float speed;
            int turn = 0;
            if (direction.x != 0.0f || direction.z != 0.0f) {
                direction.y = 0.0f;
                func_0014C410(&direction, &direction);
                speed = data_00257CE4->speed;
                if (speed > 1.3888888f) {
                    turn = 1;
                }
            }
            if (!turn) {
                func_0014C370(&direction, &frame->normal, -frame->scale);
                position.x += direction.x;
                position.z += direction.z;
                return;
            }
            Vector3 facing;
            data_00257CE8->func_000C1300(&owner->angles, &facing);
            float cosine = func_0014C800(&direction, &facing);
            owner->speed = speed;
            if (cosine > 0.7f) {
                func_000E5A90((int)frame);
            } else if (cosine < -0.7f) {
                func_000E5B20((int)frame);
            } else {
                Vector3 side;
                func_0014C3B0(&side, &facing, &direction);
                if (side.y >= 0.0f) {
                    func_000E5BC0((int)frame);
                } else {
                    func_000E5C50((int)frame);
                }
            }
            if (owner->speed > 1.6203704f) {
                owner->speed = 1.6203704f;
            }
            data_00257CE8->func_000C1DF0(&data_00257CE4->point, &direction);
            owner->flags |= 0x10000;
            owner->flags &= ~0x8000;
            return;
        }
    }
}
