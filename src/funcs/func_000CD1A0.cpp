// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x70];
    float value_70;
    char unknown_74[0x30];
    unsigned int flags;

    void func_000C5B50(int *handle);
};

struct Limits_000CC020;

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

    float func_000CCAE0();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
};

/* const: 0x20000 */
// Slot 10: without the owner's flag 2, state 10; with it, the owner gets flag 0x20000 and, unless it has flag 8, the
// result of func_000CCAE0 at its 0x70.
void Object_000CCE00::func_000CD1A0()
{
    if (!(owner->flags & 2)) {
        state = 10;
        return;
    }
    owner->flags |= 0x20000;
    if (!(owner->flags & 8)) {
        owner->value_70 = func_000CCAE0();
    }
}
