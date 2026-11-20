/* sym: ??0Object_00117510@@QAE@PAUNode@@HI@Z = 0x001174D0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00117510@@UAE@XZ = 0x00117510 */
/* sym: ?func_00011C90@Object_00117510@@UAEXXZ = 0x001178B0 */
/* sym: ?func_00011C90_2@Object_00117510@@UAEXXZ = 0x00117750 */
/* sym: ?func_00011C90_4@Object_00117510@@UAEXXZ = 0x00023F10 */
/* sym: ?func_00011C90_6@Object_00117510@@UAEXXZ = 0x00023F10 */
/* sym: ?func_00011C90_8@Object_00117510@@UAEXXZ = 0x00023F10 */
extern "C" void *memset(void *destination, int value, unsigned int size);

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

// The class whose table is at 0x1D7778: overrides slots 1, 4, 7, 10, 13 of Node. Its constructor clears
// everything from +0x44 to the end of the object (0x410 bytes) and sets +0x40c to -1.
struct Object_00117510 : Node {
    Object_00117510(Node *owner, int id, unsigned int flags);
    virtual ~Object_00117510();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_044[0x3c8];
    int value_40c;
};

Object_00117510::Object_00117510(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    memset(unknown_044, 0, 0x410 - 0x44);
    value_40c = -1;
}
