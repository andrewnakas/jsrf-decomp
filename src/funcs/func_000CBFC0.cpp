// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;

    void func_000C5B50(int *handle);
};

// func_00033800 only returns 1; this unit calls it directly with the owner in ecx.
struct Object_000265A0 {
    int func_00033800(int unused);
};

struct Limits_000CC020 {
    char unknown_00[0x38];
    int value_38;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE320 (constructor func_000CC620, destructor func_000CC680).
struct Object_000CCE00 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CCE00();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CBF20();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();
    virtual void func_000CC020();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
};

// Slot 14: with the owner's flag 0x100, the owner gets flag 0x20; otherwise func_00033800 on the field at 0x38 of
// the object at 0x30 decides between clearing its flag 0x10 and setting 0x20. State 12 either way.
void Object_000CCE00::func_000CBFC0()
{
    if (owner->flags & 0x100) {
        owner->flags |= 0x20;
        state = 12;
        return;
    }
    if (!((Object_000265A0 *)owner)->func_00033800(limits->value_38)) {
        owner->flags |= 0x20;
        state = 12;
        return;
    }
    owner->flags &= ~0x10;
    state = 12;
}
