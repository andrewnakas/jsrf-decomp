/* sym: ?func_00011C90@Object_0010E8F0@@UAEXXZ = 0x0010EB10 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};


struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    int func_00107AB0();
};

unsigned int func_0014C6A0(float value);
void func_001087D0(int handle, unsigned int count, int *values, int value);

// A direct child of Node (constructor func_0010E8F0, table 0x1D23F0, destructor func_0010EAB0) that holds a resource
// at 0x4c; slot 1 runs the handlers of data_002216E0 by the mode at 0x160.
struct Object_0010E8F0 : Node {
    virtual ~Object_0010E8F0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    int unknown_040;
    unsigned int value_44;
    char unknown_048[8];
    int minutes[2];
    char unknown_058[8];
    int seconds[2];
    char unknown_068[8];
    int hundredths[2];
    char unknown_078[0xc];
    float time;
    char unknown_088[0xd4];
    int value_15c;
    int mode;
    char unknown_164[8];
    int owner;
    int result;
};

extern void (Object_0010E8F0::*data_002216E0[])();

// Slot 1: unless 0x15c is set, with 0x44 negative, takes func_00107AB0 of the owner (id at 0x16c) at 0x170; runs the
// handler of data_002216E0 for the mode at 0x160; keeps the time at 0x84 within 0 to 3600 seconds and splits it into
// minutes (0x50), seconds (0x60) and hundredths (0x70), two digits each (func_001087D0).
void Object_0010E8F0::func_00011C90()
{
    if (!value_15c && (value_44 & 0x80000000)) {
        Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(owner);
        if (object) {
            result = object->func_00107AB0();
        }
    }
    (this->*data_002216E0[mode])();
    if (time < 0.0f) {
        time = 0.0f;
    }
    if (time > 3600.0f) {
        time = 3600.0f;
    }
    unsigned int whole = func_0014C6A0(time);
    func_001087D0(whole / 60, 2, minutes, 0);
    func_001087D0(whole % 60, 2, seconds, 0);
    float fraction = ((time - whole) * 10.0f) * 10.0f;
    unsigned int hundred = func_0014C6A0(fraction);
    func_001087D0(hundred, 2, hundredths, 0);
}
