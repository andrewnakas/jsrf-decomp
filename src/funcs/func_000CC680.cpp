/* sym: ??1Object_000CCE00@@UAE@XZ = 0x000CC680 */
/* sym: ?func_000CD1E0@Object_000CCE00@@UAEXXZ = 0x000CC6E0 */
/* sym: ?func_00011C90@Object_000CCE00@@UAEXXZ = 0x000CD050 */
// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x68];
    int value_68;
    char unknown_6c[0x38];
    unsigned int flags;

    void func_000C5B50(int *handle);
};
struct Limits_000CC020;

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE320 (constructor func_000CC620).
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
    char unknown_34[0x38];
    int handle;
};

// Releases the handle at 0x6c through the owner (func_000C5B50) when it is set.
Object_000CCE00::~Object_000CCE00()
{
    if (handle != -1) {
        owner->func_000C5B50(&handle);
    }
}
