/* sym: ?func_000C8F30@Object_000D47B0@@UAEXXZ = 0x000D4860 */
/* const: 0x200000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

// A trigger in the list at 0x39c: its kind, a scale at 0x28 for the direction at 0x2c, the next one at 0x38.
struct Frame_000C1490 {
    int kind;
    char unknown_04[0x24];
    float scale;
    Vector3 normal;
    Frame_000C1490 *next;
};

struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *out);
    void func_000C1490(Vector3 *out, Frame_000C1490 *frame, float first, float second);
    void func_000C1DF0(const Vector3 *from, Vector3 *direction);
};

// The object at data_00257CE4: a speed at 0xb4 and a position at 0xb8.
struct Object_000C1270 {
    char unknown_00[0xb4];
    float speed;
    Vector3 position;
};

struct Game {
    void *func_000128C0(int id);
};

// What func_000128C0(0x2c) returns.
struct Player_000D4860 {
    char unknown_000[0xe60];
    unsigned int count;
};

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *position);
};

struct Object_00047470 {
    void func_00047970(void *block, int flags);
    void func_000480C0(unsigned int mode);
};


// What func_00025700 (5, ...) returns: its models first.
struct Bank_000D4860 {
    Object_00047470 **models;
};

// The owner at 0xb0: flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;

    int func_000C5B10(int message, void *data);
};

void *func_00025700(unsigned int index, int first, int second, int third);
void func_000C4B70(int value);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);

extern Game *data_0022FCE0;
extern Object_000C1270 *data_00257CE4;
extern Object_00157F10 *data_00257CE8;

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

// The child of Node whose table is at 0x1CE1C8 (a second base at 0x44, not declared here).
struct Object_000C7910 : Node {
    virtual void func_000C8F30();

    void *base_44;
    float matrix[3];
    Angles_000C1300 angles;
    float speed;
    char unknown_064[0x2c];
    unsigned int flags_90;
    char unknown_094[0x1c];
    Object_000C5B50 *owner;
    char unknown_0b4[0x1c];
    Vector3 position;
    char unknown_0dc[0x50];
    Vector3 velocity;
    char unknown_138[0x4c];
    Object_00047470 *model;
    char unknown_188[0x14];
    void *blocks[3];
    char unknown_1a8[0x1f4];
    Frame_000C1490 *frames;

    int func_000C8500();
    void func_000C83A0();
    void func_000C8400();
    void func_000C8460();
    void func_000C84B0();
};

struct Object_000D47B0 : Object_000C7910 {
    virtual void func_000C8F30();

    char unknown_3a0[0x2c];
    int active;
};

// Slot 46: the base's when not active. Else the frames at 0x39c push the object (kind 1: half their scale along
// their direction) until a kind-0 frame: it reflects the velocity (func_000C1490), takes the speed at 0xb4 of
// data_00257CE4 when it moved, and unless the player's count at 0xe60 is set backs the object out along the frame
// (flag 0x80). With it set: the facing decides the turn (func_000C83A0 / C8400 / C8460 / C84B0), the speed is capped,
// the object faces the position at 0xb8, takes flag 0x200000, sends effect 0x27, swaps to model 1 of bank (5, 4) and
// tells the owner 0x10 and 0x13.
void Object_000D47B0::func_000C8F30()
{
    if (!active) {
        Object_000C7910::func_000C8F30();
        return;
    }
    float newSpeed = 0.0f;
    for (Frame_000C1490 *frame = frames; frame; frame = frame->next) {
        if (frame->kind == 0) {
            if (owner->flags & 1) {
                owner->flags |= 0x800;
            }
            Vector3 *at = &velocity;
            data_00257CE8->func_000C1490(at, frame, 0.1f, 1.0f);
            if (at->x != 0.0f || velocity.z != 0.0f) {
                velocity.y = 0.0f;
                func_0014C410(at, at);
                newSpeed = data_00257CE4->speed;
            }
            Player_000D4860 *player = (Player_000D4860 *)data_0022FCE0->func_000128C0(0x2c);
            int turn = 0;
            if (player && player->count > 0) {
                turn = 1;
            }
            if (!turn) {
                if (!active && func_000C8500()) {
                    return;
                }
                func_0014C370(at, &frame->normal, -frame->scale);
                position.x += at->x;
                flags_90 |= 0x80;
                position.z += velocity.z;
                return;
            }
            Vector3 facing;
            data_00257CE8->func_000C1300(&angles, &facing);
            float dot = func_0014C800(at, &facing);
            speed = newSpeed;
            if (dot > 0.7f) {
                func_000C83A0();
            } else if (dot < -0.7f) {
                func_000C8400();
            } else {
                Vector3 cross;
                func_0014C3B0(&cross, &facing, at);
                if (cross.y >= 0.0f) {
                    func_000C8460();
                } else {
                    func_000C84B0();
                }
            }
            if (speed > 2.3148148f) {
                speed = 2.3148148f;
            }
            data_00257CE8->func_000C1DF0(&data_00257CE4->position, at);
            flags_90 = (flags_90 & ~0x05008000) | 0x200000;
            func_001BAA00();
            func_001BAAA0(matrix);
            model->func_00047970(blocks[0], 0);
            model->func_000480C0(8);
            func_001BAB20(&facing, 0);
            Object_000607B0 *effects = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
            if (effects) {
                effects->func_000651E0(0x27, &facing, 0);
            }
            model->func_000480C0(0);
            func_000C4B70(0);
            model = ((Bank_000D4860 *)func_00025700(5, 4, 0, 0))->models[1];
            flags_90 &= ~0x1000;
            active = 0;
            model->func_000480C0(0xb);
            func_001BAB20(&facing, 0);
            owner->func_000C5B10(0x10, &facing);
            owner->func_000C5B10(0x13, &facing);
            func_001BAA50();
            return;
        }
        if (frame->kind == 1) {
            Vector3 *at = &velocity;
            func_0014C370(at, &frame->normal, frame->scale * -0.5f);
            position.x += velocity.x;
            position.z += velocity.z;
        }
    }
}
