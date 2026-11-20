// The base of two small state machines (tables 0x1CDDB8 and 0x1CDDCC): slots 0 and 1 are pure, slots 2 and 3
// take an argument and do nothing, slot 4 is the destructor (func_000C4060).
struct Object_000C4070 {
    virtual void func_000C3D90() = 0;
    virtual void func_00011C90() = 0;
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000C4070();

    int unknown_04;
};

// The state machine whose table is at 0x1CDDB8 (constructor func_000C4090); slot 1 is empty.
struct Object_000C3D90 : Object_000C4070 {
    virtual void func_000C3D90();
    virtual void func_00011C90();

    int state;
};

extern void (Object_000C3D90::*data_00216148[])();

// Slot 0: runs the handler of the current state.
void Object_000C3D90::func_000C3D90()
{
    (this->*data_00216148[state])();
}
