/* sym: ?func_00011C90@Object_0007BC10@@UAEXXZ = 0x0007BDD0 */
// The object at 0x1EFFB0.
struct Object_00039BE0 {
    void func_0003A900();
};

extern Object_00039BE0 data_001EFFB0;

// The node class whose table is at 0x1CCEB8 (constructor 0x7BC10, destructor 0x7BC90): a state machine whose
// handlers for states 0 to 0x3f are in the table at 0x20D2B8.
struct Object_0007BC10 {
    virtual ~Object_0007BC10();
    virtual void func_00011C90();

    char unknown_04[0x44];
    unsigned int state;
};

extern void (Object_0007BC10::*data_0020D2B8[0x40])();

// Slot 1: runs the handler of the state (below 0x40), then for states 0x14 to 0x27 and 0x2c to 0x2f runs
// func_0003A900 of 0x1EFFB0.
void Object_0007BC10::func_00011C90()
{
    if (state < 0x40) {
        (this->*data_0020D2B8[state])();
    }
    switch (state) {
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
        data_001EFFB0.func_0003A900();
        break;
    }
}
