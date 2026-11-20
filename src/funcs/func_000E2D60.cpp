/* sym: ?func_000F6770@Object_000E2F60@@UAEXXZ = 0x000E2D60 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// One frame of the list at 0x1d4: free while 0x0 is 0, the next one at 0x38.
struct Frame_000C1490 {
    int used;
    char unknown_04[0x34];
    Frame_000C1490 *next;
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1490(Vector3 *direction, Frame_000C1490 *frame, float first, float second);
};

extern Object_00157F10 *data_00257CE8;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0x2c: a count at 0xe60.
struct Object_0002C000 {
    char unknown_000[0xe60];
    unsigned int count;
};

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *position);
};

// A posed model (the one at 0x130).
struct Object_00047470 {
    void func_00047970(void *block, int index);
    void func_000480C0(unsigned int part);
};

// The object a behaviour serves (the owner at 0xb0).
struct Object_000C5B50 {
    char unknown_00[0x5c];
    int value_5c;

    int func_000C5B10(int message, void *data);
};

// What func_00025700 (5, 5) returns: its models first.
struct Bank_000E2D60 {
    Object_00047470 **models;
};

void *func_00025700(unsigned int index, int first, int second, int third);
void func_000C4BE0(int kind, Vector3 *position, Vector3 *direction, int angle);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

// The link of a chain (the second base, at 0x44).
struct Object_000C60C0 {
    virtual void func_000C6090();
};

// The child of Node whose table is at 0x1CF220 (0x200 bytes), a link of the chain at 0x44.
struct Object_000F55E0 : Node, Object_000C60C0 {
    virtual void func_000F6770();

    void func_000F5890();
    void func_000F58E0();

    Vector3 position;
    int angles[3];
    char unknown_060[0x30];
    unsigned int flags_90;
    char unknown_094[0x1c];
    Object_000C5B50 *owner;
    char unknown_0b4[0xc];
    Vector3 position_c0;
    char unknown_0cc[0x1c];
    Vector3 direction;
    char unknown_0f4[0x3c];
    Object_00047470 *model;
    char unknown_134[0x14];
    void *block;
    char unknown_14c[0x88];
    Frame_000C1490 *frames;
    char unknown_1d8[0x28];
};

// The Object_000F55E0 child whose table is at 0x1CEAC0 (0x204 bytes), built by the factory func_000E2F60.
struct Object_000E2F60 : Object_000F55E0 {
    virtual void func_000F6770();

    int state;
};

// Slot 35: in state 0 runs Object_000F55E0's slot. Otherwise, with no used frame in the list at 0x1d4, clears flag
// 0x800000 at 0x90; with one, turns towards it (func_000C1490, flattened and normalised) and, when object 0x2c has a
// count, turns left or right (func_000F5890 / func_000F58E0) by the side the direction lies on, poses model parts 9
// and 0xb (kind 0x27 of object 0xe8 at the first, func_000C4BE0 at the second), takes model 3 of bank (5, 5), drops
// to state 0 and sends the owner messages 0x10 and 0x13 with the point.
void Object_000E2F60::func_000F6770()
{
    if (!state) {
        Object_000F55E0::func_000F6770();
        return;
    }
    for (Frame_000C1490 *frame = frames; frame; frame = frame->next) {
        if (!frame->used) {
            Vector3 *at = &direction;
            data_00257CE8->func_000C1490(at, frame, 0.1f, 1.0f);
            if (at->x != 0.0f || direction.z != 0.0f) {
                direction.y = 0.0f;
                func_0014C410(at, at);
            }
            Object_0002C000 *counter = (Object_0002C000 *)data_0022FCE0->func_000128C0(0x2c);
            if (counter && counter->count > 0) {
                owner->value_5c = 0;
                Vector3 point;
                func_0014C3B0(&point, &position_c0, at);
                if (point.y >= 0.0f) {
                    func_000F5890();
                } else {
                    func_000F58E0();
                }
                flags_90 = (flags_90 & 0xfcff7fff) | 0xa00000;
                func_001BAA00();
                func_001BAAA0(&position.x);
                model->func_00047970(block, 0);
                model->func_000480C0(9);
                func_001BAB20(&point, 0);
                Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
                if (object) {
                    object->func_000651E0(0x27, &point, 0);
                }
                model->func_000480C0(0xb);
                func_001BAB20(&point, 0);
                func_000C4BE0(0, &point, at, angles[1]);
                model = ((Bank_000E2D60 *)func_00025700(5, 5, 0, 0))->models[3];
                flags_90 &= ~0x1000;
                state = 0;
                owner->func_000C5B10(0x10, &point);
                owner->func_000C5B10(0x13, &point);
                func_001BAA50();
                return;
            }
            break;
        }
    }
    flags_90 &= ~0x800000;
}
