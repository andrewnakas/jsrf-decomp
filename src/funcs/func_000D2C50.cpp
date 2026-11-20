/* sym: ?func_00011C90@Object_000D27F0@@UAEXXZ = 0x000D2C50 */
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

// An axis and an angle (func_001BAC70 reads the angle at 0xc).
struct Rotation_000D2B90 {
    Vector3 axis;
    int angle;
};

struct Object_0006DB80 {
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    int func_000C1D40(int *first, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC70(Rotation_000D2B90 *rotation);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);
void func_000FEC30(int value, const Vector3 *position);

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

// The holder of the model at 0xef4.
struct Holder_000D2C50 {
    Object_00047470 *model;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x40];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;

    void func_000C5AD0(int amount);
    int func_000C5B10(int message, void *data);
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE450 (constructor func_000D27F0).
struct Object_000D27F0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D27F0();

    void func_000D1D30();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int count;
    char unknown_014[0xeb0];
    Rotation_000D2B90 rotation;
    char unknown_ed4[0x20];
    Holder_000D2C50 *holder;
    char unknown_ef8[0x18];
    void *data_f10;
    char unknown_f14[0x1c];
    int value_f30;
    char unknown_f34[0xb4];
    int value_fe8;
    int value_fec;
    int value_ff0;
    int effect_ff4;
    int value_ff8;
};

// Slot 1: runs func_000D1D30; unless the owner has the flag 0x2000: when func_000C1D40 of data_00257CE8 says so
// (with 0xfe8, 0xff0 and 0xfec), gives the owner that flag and func_000C5AD0(1), state 0x1b with 0x16 at 0xf30, the
// count cleared, 1 at 0xff8 and message 0x11 at the owner's position; else func_000FEC30 with the owner's 0x9c there.
// Then, with an effect at 0xff4, shows it at bone 9 of the model at 0xef4 posed at the owner's position, turned by
// the rotation at 0xec4 and a half turn past the owner's heading.
void Object_000D27F0::func_00011C90()
{
    func_000D1D30();
    if (owner->flags & 0x2000) {
        return;
    }
    if (data_00257CE8->func_000C1D40(&value_fe8, &value_ff0, &value_fec)) {
        owner->flags |= 0x2000;
        state = 0x1b;
        value_f30 = 0x16;
        count = 0;
        owner->func_000C5AD0(1);
        value_ff8 = 1;
        owner->func_000C5B10(0x11, &owner->position);
    } else {
        func_000FEC30(owner->value_9c, &owner->position);
    }
    if (effect_ff4 != -1) {
        func_001BA9C0();
        func_001BAAA0(&owner->position.x);
        func_001BAC70(&rotation);
        func_001BB330(owner->angles.y + 0x8000);
        holder->model->func_00047970(data_f10, 0);
        holder->model->func_000480C0(9);
        Vector3 point;
        func_001BAB20(&point, 0);
        func_001BAA50();
        data_00251F78.func_0006DFC0(effect_ff4, &point);
    }
}
