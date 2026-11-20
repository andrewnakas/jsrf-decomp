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
};

extern Object_00157F10 *data_00257CE8;

void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
void __fastcall func_0014CD50(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);
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

struct Limits_000DE510 {
    char unknown_00[0xc];
    float speed;
};

struct Settings_000DE510 {
    Limits_000DE510 *limits;
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[0x8];
    Vector3 position;
    char unknown_020[0x104];
    Vector3 direction;
    char unknown_130[0x4c];
    unsigned int count;
    char unknown_180[0x128];
    Settings_000DE510 *settings;
    Frame_000C1490 *frames;

    void func_000DDB30();
    void func_000DDB90();
    void func_000DDBF0();
    void func_000DDC50();
    void func_000DE510();
};

// Finds the first kind-9 frame of the list at 0x2ac and pushes the object off it: the flat part of the frame's
// normal (func_0014CD50), normalised, or the frame's other vector when that is zero; the owner's speed is set to 1.39
// and it turns by how its facing meets the direction (func_000DDB30 ahead, func_000DDB90 behind, func_000DDBF0 or
// func_000DDC50 to either side). The frame's push (clamped to [0, the limit at +0xc of the settings]) plus 1 moves the
// position; the owner's flags change, it gets message 0x10, and after ten pushes (0x17c) the state becomes 0x1f with
// the owner's flag 0x400000.
void Object_000DCBC0::func_000DE510()
{
    for (Frame_000C1490 *frame = frames; frame; frame = frame->next) {
        if (frame->kind == 9) {
            func_0014CD50(&direction, &frame->normal);
            direction.y = 0.0f;
            if (direction.x == 0.0f && direction.z == 0.0f) {
                func_0014CD50(&direction, &frame->along);
            } else {
                func_0014C410(&direction, &direction);
            }
            Vector3 facing;
            data_00257CE8->func_000C1300(&owner->angles, &facing);
            float cosine = func_0014C800(&direction, &facing);
            owner->speed = 1.3888888f;
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
            owner->speed = 1.3888888f;
            if (frame->scale < 0.0f || frame->scale > settings->limits->speed) {
                frame->scale = settings->limits->speed;
            }
            func_0014C730(&position, &direction, frame->scale + 1.0f);
            owner->flags &= 0xf7ff7ff9;
            owner->flags |= 0xa00000;
            owner->func_000C5B10(0x10, &owner->position);
            if (++count >= 10) {
                state = 0x1f;
                owner->flags |= 0x400000;
            }
            return;
        }
    }
}
