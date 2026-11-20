struct Vector3 {
    float x;
    float y;
    float z;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;

    void func_000C5B50(int *handle);
};

// A point of the route at 0x34 (0x18 bytes).
struct Point_000D3C50 {
    Vector3 position;
    char unknown_0c[0xc];
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

    void func_000D27A0();
    void func_000D34B0();
    int func_000D36A0(Vector3 *position, int flags);
    void func_000D3C50();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[8];
    Vector3 position;
    char unknown_020[0x14];
    Point_000D3C50 *points;
    int point;
    char unknown_03c[0x18];
    float value_54;
    char unknown_058[0x30];
    int value_88;
    char unknown_08c[4];
    Vector3 targets[0x13];
    char unknown_174[0xd48];
    int target;
    char unknown_ec0[0x70];
    int mode;
    char unknown_f34[0xc8];
    int handle;
};

// Entry 4 of the handlers at 0x2169E0. Unless the owner has the flag 0x4000000: follows the current point
// (func_000D36A0) and runs func_000D34B0, clearing the owner's flag 0x2000000 on 0 or 3, setting it on 1, and on 2 going
// to state 6 with the flags 0x6000000 cleared. With that flag: state 5 at the target point (0xebc of the points at
// 0x90), mode 4 at 0xf30, the owner's flags 0x6000000 cleared, 0x88 from the value at 0x54 (above 0.7: 0, below -0.7:
// 2, else 1), func_000D27A0, and the owner's handle at 0xffc handed back.
void Object_000D27F0::func_000D3C50()
{
    Point_000D3C50 *current = &points[point];
    if (!(owner->flags & 0x4000000)) {
        switch (func_000D36A0(&current->position, 0)) {
        case 0:
        case 3:
            owner->flags &= ~0x2000000;
            break;
        case 1:
            owner->flags |= 0x2000000;
            break;
        case 2:
            state = 6;
            owner->flags &= ~0x6000000;
            break;
        }
        func_000D34B0();
        return;
    }
    position = targets[target];
    state = 5;
    mode = 4;
    owner->flags &= ~0x6000000;
    if (value_54 > 0.7f) {
        value_88 = 0;
    } else if (value_54 < -0.7f) {
        value_88 = 2;
    } else {
        value_88 = 1;
    }
    func_000D27A0();
    owner->func_000C5B50(&handle);
}
