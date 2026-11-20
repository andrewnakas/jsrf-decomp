struct Vector3 {
    float x;
    float y;
    float z;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x54];
    unsigned int flags;

    int func_000C5B10(int message, void *data);
    void func_000C5B50(int *handle);
};

// The object in data_00257CE4.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

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
    void func_000D3FE0();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int count;
    char unknown_014[0xf1c];
    int mode;
    char unknown_f34[0xc8];
    int handle;
};

// Entry 14 of the handlers at 0x2169E0. Unless the owner has the flag 0x4000000: follows the point at 0x7c of
// data_00257CE4 (lifted by 10 unless the owner has the flag 0x2000000; func_000D36A0) and runs func_000D34B0, clearing
// the owner's flag 0x2000000 on 0, setting it on 1, on 2 going to state 0xf (mode 0xb, the handle at 0xffc handed
// back) and on 3 to state 0x11 (mode 0xc), each with the flags 0x6000000 cleared and the count restarted. With that
// flag: state 0xf, mode 0xb, those flags cleared, the count restarted, func_000D27A0, the handle handed back and
// message 0x27 at the owner's position.
void Object_000D27F0::func_000D3FE0()
{
    Vector3 point = data_00257CE4->position;
    if (!(owner->flags & 0x2000000)) {
        point.y += 10.0f;
    }
    if (!(owner->flags & 0x4000000)) {
        switch (func_000D36A0(&point, 0)) {
        case 0:
            owner->flags &= ~0x2000000;
            break;
        case 1:
            owner->flags |= 0x2000000;
            break;
        case 2:
            state = 0xf;
            mode = 0xb;
            owner->flags &= ~0x6000000;
            count = 0;
            owner->func_000C5B50(&handle);
            break;
        case 3:
            state = 0x11;
            mode = 0xc;
            owner->flags &= ~0x6000000;
            count = 0;
            break;
        }
        func_000D34B0();
        return;
    }
    state = 0xf;
    mode = 0xb;
    owner->flags &= ~0x6000000;
    count = 0;
    func_000D27A0();
    owner->func_000C5B50(&handle);
    owner->func_000C5B10(0x27, &owner->position);
}
