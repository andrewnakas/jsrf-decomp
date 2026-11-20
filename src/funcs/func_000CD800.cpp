// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x5c];
    float value_5c;
    char unknown_60[0x44];
    unsigned int flags;

    int func_000C59A0();
};

// One entry of the list at 0x70 (0x18 bytes).
struct Entry_000CD5C0 {
    char unknown_00[0xc];
    float value_0c;
    char unknown_10[8];
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE364; slots 8 and 9 are pure.
struct Object_000CD1E0 : Object_000CC600 {
    Object_000CD1E0();
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual void func_000CD440();
    virtual float func_000CD4F0();
    virtual void func_000CD390();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int unknown_10;
    char unknown_14[0x2c];
    float unknown_40;
    char unknown_44[0x2c];
    Entry_000CD5C0 *entries;

    void func_000CD310(float rate);
    void func_000CD5C0();
};

// Slot 6: when the owner's test passes (func_000C59A0), copies the field at 0xc of the first entry to the owner's
// 0x5c, clears its flags 0x100 and 1, moves to state 2 with the count at 0x10 cleared, and runs func_000CD5C0.
void Object_000CD1E0::func_000CD800()
{
    if (owner->func_000C59A0()) {
        owner->value_5c = entries->value_0c;
        owner->flags &= ~0x100;
        owner->flags &= ~1;
        state = 2;
        unknown_10 = 0;
        func_000CD5C0();
    }
}
