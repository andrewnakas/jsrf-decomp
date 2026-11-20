/* sym: ??0Object_000C3D90@@QAE@XZ = 0x000C4090 */
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

// Runs the handler of its current state (table 0x1CDDB8).
struct Object_000C3D90 : Object_000C4070 {
    Object_000C3D90();
    virtual void func_000C3D90();
    virtual void func_00011C90();

    int state;
};

Object_000C3D90::Object_000C3D90()
{
    state = 0;
}
