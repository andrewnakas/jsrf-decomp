/* sym: ?func_00011C90@Object_000D8A40@@UAEXXZ = 0x000D8E90 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00157F10 {
    int func_000C1D40(int *first, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *position);
    void func_00060730(int key, Vector3 *direction);
    void func_00060810(int key);
};

struct Object_0006DB80 {
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

struct Object_000DADD0 {
    void func_000DADD0();
};

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Holder_000D8A40 {
    Object_00047470 *model;
};

// The owner at 0x4: its position at 0x44, a key at 0x9c, flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x4c];
    int key;
    char unknown_a0[4];
    unsigned int flags;

    void func_000C5AD0(int value);
    int func_000C5B10(int message, void *data);
};

void func_000FEC30(int key, const Vector3 *position);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE63C (constructor func_000D8A40).
struct Object_000D8A40 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D8A40();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[0x8c];
    int handle_98;
    int sound_9c;
    int value_a0;
    Holder_000D8A40 *holder;
    char unknown_0a8[0x18];
    void *handle_c0;
    char unknown_0c4[0x1c];
    int state_e0;
    char unknown_0e4[0xd4];
    int value_1b8;
    int value_1bc;
    int value_1c0;
    int key_1c4;
    int value_1c8;

    void func_000D87E0();
    void func_000D89D0(Vector3 *position, Vector3 *direction);
};

// Slot 1: runs func_000D87E0; unless the owner has flag 0x2000 at 0xa4: when data_00257CE8 takes the three values at
// 0x1b8 (func_000C1D40) the owner takes flag 0x2000 and loses 0x01008000, state 11 at 0x8 and 0xe0, the owner gets
// func_000C5AD0(1), object 0x98 is stopped, 0x1c8 = 1, the sound at 0x9c stops and the owner gets message 0x11; else
// func_000FEC30 with the owner's key and position. The key at 0x1c4 follows the model's part 9 and, without 0xa0, the
// sound at 0x9c follows the point and direction of func_000D89D0.
void Object_000D8A40::func_00011C90()
{
    func_000D87E0();
    if (owner->flags & 0x2000) {
        return;
    }
    if (data_00257CE8->func_000C1D40(&value_1b8, &value_1c0, &value_1bc)) {
        owner->flags |= 0x2000;
        owner->flags &= 0xfeff7fff;
        state = 11;
        state_e0 = 11;
        owner->func_000C5AD0(1);
        Object_000DADD0 *object = (Object_000DADD0 *)data_0022FCE0->func_000128C0(handle_98);
        if (object) {
            object->func_000DADD0();
            handle_98 = -1;
        }
        value_1c8 = 1;
        Object_000607B0 *sounds = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (sounds) {
            sounds->func_00060810(sound_9c);
        }
        owner->func_000C5B10(0x11, &owner->position);
    } else {
        func_000FEC30(owner->key, &owner->position);
    }
    if (key_1c4 != -1) {
        Vector3 position;
        func_001BA9C0();
        func_001BAAA0(&owner->position.x);
        holder->model->func_00047970(handle_c0, 0);
        holder->model->func_000480C0(9);
        func_001BAB20(&position, 0);
        func_001BAA50();
        data_00251F78.func_0006DFC0(key_1c4, &position);
    }
    if (!value_a0) {
        Vector3 position;
        Vector3 direction;
        func_000D89D0(&position, &direction);
        Object_000607B0 *sounds = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (sounds) {
            sounds->func_000606C0(sound_9c, &position);
            sounds->func_00060730(sound_9c, &direction);
        }
    }
}
