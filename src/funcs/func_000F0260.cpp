struct Vector3;

// The owner at 0x4.
struct Object_000C5B50 {
    char unknown_00[0x5c];
    float value_5c;
    char unknown_60[0x10];
    float height;
    char unknown_74[0x30];
    unsigned int flags;
};

struct Limit_000F02F0 {
    char unknown_00[8];
    float height;
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE364; slots 8 and 9 are pure.
struct Object_000CD1E0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CD1E0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual float func_000CD440();
    virtual float func_000CD4F0();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;

    void func_000CD310(float rate);
    void func_000CD5C0();
};

// The class whose table is at 0x1CEFAC; this is a handler of its table at 0x21A900.
struct Object_000EDC30 : Object_000CD1E0 {
    virtual void func_000D77D0();
    virtual void func_000D7880();

    char unknown_014[0xc0];
    Limit_000F02F0 *limit;

    void func_000EF5F0();
    void func_000F0260();
};

// A handler of the table at 0x21A900: while the owner's 0x5c is above 0, brings it toward 0 (func_000CD310) and runs
// slot 11. Without the owner's flag 0x2000000, func_000EF5F0, and once the owner's 0x70 is above the limit's 0x8,
// func_000CD5C0 and state 2 with the count at 0x10 cleared; with the flag, state 5 once 0x5c is down to 0.
void Object_000EDC30::func_000F0260()
{
    if (owner->value_5c > 0.0f) {
        func_000CD310(0.0f);
        func_000CD4F0();
    }
    if (!(owner->flags & 0x2000000)) {
        func_000EF5F0();
        if (owner->height > limit->height) {
            func_000CD5C0();
            state = 2;
            count = 0;
        }
    } else if (owner->value_5c <= 0.0f) {
        state = 5;
    }
}
