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
    char unknown_04[0x18];
    Vector3 along;
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

// The object in data_00257CE4: a speed at 0xb4 and a point at 0xb8.
struct Object_000C1270 {
    char unknown_00[0xb4];
    float value_b4;
    Vector3 value_b8;
};

extern Object_000C1270 *data_00257CE4;

void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);

// The owner at 0x4: position at 0x44, angles at 0x50, a speed at 0x5c and flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    float speed;
    char unknown_60[0x44];
    unsigned int flags;

    int func_000C5B10(int message, void *data);
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[0x8];
    Vector3 position;
    char unknown_020[0x104];
    Vector3 direction;
    char unknown_130[0x17c];
    Frame_000C1490 *frames;

    void func_000DDB30();
    void func_000DDB90();
    void func_000DDBF0();
    void func_000DDC50();
    void func_000DE6C0();
};

// Finds the first kind-0 frame of the list at 0x2ac and rides it: the owner gets flag 0x800 (unless 0x1000000) and
// the direction at 0x124 comes from the frame (func_000C1490). When that direction is flat and the object at
// data_00257CE4 runs faster than 1.39, the owner takes its speed and turns by how its facing meets the direction
// (func_000DDB30 ahead, func_000DDB90 behind, func_000DDBF0 or func_000DDC50 to either side), its speed capped at
// 2.78; the direction is aimed (func_000C1DF0), the owner's flags change and it gets message 0x10. Otherwise the
// frame's normal, scaled back by its push, moves the position on x and z and the owner gets flag 0x80.
/* const: 0x200000 */
void Object_000DCBC0::func_000DE6C0()
{
    for (Frame_000C1490 *frame = frames; frame; frame = frame->next) {
        if (frame->kind == 0) {
            if (!(owner->flags & 0x1000000)) {
                owner->flags |= 0x800;
            }
            data_00257CE8->func_000C1490(&direction, frame, 0.0f, 1.0f);
            int fast = 0;
            float speed;
            if (direction.x != 0.0f || direction.z != 0.0f) {
                direction.y = 0.0f;
                func_0014C410(&direction, &direction);
                speed = data_00257CE4->value_b4;
                if (speed > 1.3888888f) {
                    fast = 1;
                }
            }
            if (!fast) {
                func_0014C370(&direction, &frame->normal, -frame->scale);
                Vector3 *step = &direction;
                position.x += step->x;
                position.z += direction.z;
                owner->flags |= 0x80;
                return;
            }
            Vector3 facing;
            data_00257CE8->func_000C1300(&owner->angles, &facing);
            float cosine = func_0014C800(&direction, &facing);
            owner->speed = speed;
            if (cosine > 0.7f) {
                func_000DDB30();
            } else if (cosine < -0.7f) {
                func_000DDB90();
            } else {
                Vector3 side;
                func_0014C3B0(&side, &facing, &direction);
                if (side.y >= 0.0f) {
                    func_000DDBF0();
                } else {
                    func_000DDC50();
                }
            }
            if (owner->speed > 2.7777777f) {
                owner->speed = 2.7777777f;
            }
            data_00257CE8->func_000C1DF0(&data_00257CE4->value_b8, &direction);
            owner->flags &= ~0x8000;
            owner->flags |= 0x200000;
            owner->func_000C5B10(0x10, &owner->position);
            return;
        }
    }
}
