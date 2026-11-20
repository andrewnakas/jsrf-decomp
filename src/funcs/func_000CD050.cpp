/* sym: ?func_00011C90@Object_000CCE00@@UAEXXZ = 0x000CD050 */
struct Owner_000CBF90 {
    char unknown_00[0x68];
    int value_68;
    char unknown_6c[0x38];
    unsigned int flags;
};

struct Limits_000CC020 {
    char unknown_00[0x54];
    int limit;
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

    void func_000CCE00();

    Owner_000CBF90 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
};

// Overrides slot 1 of the base: runs func_000CCE00.
void Object_000CCE00::func_00011C90()
{
    func_000CCE00();
}
