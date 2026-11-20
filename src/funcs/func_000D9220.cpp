struct Vector3 {
    float x;
    float y;
    float z;
};

// A trigger in the list at 0x190: its kind, a scale at 0x28 for the direction at 0x2c, the next one at 0x38.
struct Frame_000C1490 {
    int kind;
    char unknown_04[0x24];
    float scale;
    Vector3 normal;
    Frame_000C1490 *next;
};

struct Object_00157F10 {
    void func_000C1490(Vector3 *out, Frame_000C1490 *frame, float first, float second);
};

extern Object_00157F10 *data_00257CE8;

// The object at data_00257CE4: a speed at 0xb4.
struct Object_000C1270 {
    char unknown_00[0xb4];
    float speed;
};

extern Object_000C1270 *data_00257CE4;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000DADD0 {
    void func_000DADD0();
};

// The owner at 0x4: position at 0x44, velocity at 0x5c, facing at 0x74, flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float side;
    float speed;
    char unknown_64[0x10];
    Vector3 facing;
    char unknown_80[0x24];
    unsigned int flags;

    int func_000C5B10(int message, void *data);
};

void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);

struct Object_000D8A40 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[8];
    Vector3 position;
    char unknown_020[0x38];
    Vector3 velocity;
    char unknown_064[0x34];
    int target;
    char unknown_09c[0x44];
    int state_e0;
    char unknown_0e4[0xac];
    Frame_000C1490 *frames;

    void func_000D9220();
};

// At the first kind-0 frame of the list at 0x190: the velocity at 0x58 is reflected on it (func_000C1490) and, if it
// moved in x or z, flattened and normalised. If it moved and the speed at 0xb4 of data_00257CE4 is above 1.39 the
// owner stops (0x5c = 0, 0x60 = 0.926), turns to state 7 or 9 by the side the velocity lies on (func_0014C3B0), loses
// flag 0x8000 and takes 0x1000000, the object at 0x98 is stopped and the owner gets message 0x10. Otherwise the object
// backs out along the frame and the owner takes flag 0x80.
void Object_000D8A40::func_000D9220()
{
    for (Frame_000C1490 *frame = frames; frame; frame = frame->next) {
        if (frame->kind == 0) {
            Vector3 *at = &velocity;
            data_00257CE8->func_000C1490(at, frame, 0.0f, 1.0f);
            int turn = 0;
            if (at->x != 0.0f || velocity.z != 0.0f) {
                velocity.y = 0.0f;
                func_0014C410(at, at);
                if (data_00257CE4->speed > 1.3888888f) {
                    turn = 1;
                }
            }
            if (!turn) {
                func_0014C370(at, &frame->normal, -frame->scale);
                position.x += velocity.x;
                position.z += velocity.z;
                owner->flags |= 0x80;
                return;
            }
            owner->side = 0.0f;
            Vector3 cross;
            func_0014C3B0(&cross, &owner->facing, at);
            int next;
            if (cross.y >= 0.0f) {
                owner->speed = 0.9259259f;
                next = 7;
            } else {
                owner->speed = 0.9259259f;
                next = 9;
            }
            state = next;
            state_e0 = next;
            owner->flags &= ~0x8000;
            owner->flags |= 0x1000000;
            Object_000DADD0 *object = (Object_000DADD0 *)data_0022FCE0->func_000128C0(target);
            if (object) {
                object->func_000DADD0();
                target = -1;
            }
            owner->func_000C5B10(0x10, &owner->position);
            return;
        }
    }
}
