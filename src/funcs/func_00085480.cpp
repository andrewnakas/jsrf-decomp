/* sym: ?func_00011C90@Object_00086060@@UAEXXZ = 0x00085480 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
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
    char unknown_34[0x10];
};

struct Vector3 {
    float x;
    float y;
    float z;
};

// The class whose table is at 0x1CD0C0: overrides slots 1 (85480), 2 (854B0), 3 (854E0).
struct Object_00086060 : Node {
    virtual ~Object_00086060();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    int state;
    Vector3 unknown_48;
    char unknown_054[0x48];
    unsigned int flags;
};

extern void (Object_00086060::*data_0020D9DC[])();
extern void (Object_00086060::*data_0020D9F0[])();

// Slot 1: runs the handler of the state at +0x44 from the table at 0x20D9DC, or with flag 0x20 the one from 0x20D9F0
// and sets flag 0x40.
void Object_00086060::func_00011C90()
{
    if (!(flags & 0x20)) {
        (this->*data_0020D9DC[state])();
    } else {
        (this->*data_0020D9F0[state])();
        flags |= 0x40;
    }
}
