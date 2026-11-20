/* sym: ??0Object_000C41B0@@QAE@XZ = 0x000C44D0 */
/* sym: ?func_000C3D90@Object_000C41B0@@UAEXXZ = 0x000C41B0 */
// The base of two small state machines (tables 0x1CDDB8 and 0x1CDDCC): slots 0 and 1 are pure, slots 2 and 3
// empty, slot 4 the destructor.
struct Object_000C4070 {
    virtual void func_000C3D90() = 0;
    virtual void func_00011C90() = 0;
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000C4070() {}

    int unknown_04;
};

// The state machine whose table is at 0x1CDDCC; slot 1 is empty.
struct Object_000C41B0 : Object_000C4070 {
    Object_000C41B0();
    virtual void func_000C3D90();
    virtual void func_00011C90();

    int state;
    int count;
    int unknown_10;
    int unknown_14;
    int unknown_18;
};

Object_000C41B0::Object_000C41B0()
{
    state = 0;
    unknown_18 = 0;
    count = 0;
}
