/* sym: ?func_00011C90@Object_00100770@@UAEXXZ = 0x00100770 */
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

// The child of Node whose table is at 0x1D1D00.
struct Object_00100770 : Node {
    char unknown_40[0x20];
    int mode;

    virtual void func_00011C90();
};

extern void (Object_00100770::*data_0021FF88[])();

// Overrides Node's slot 1: runs the handler of the current mode.
void Object_00100770::func_00011C90()
{
    (this->*data_0021FF88[mode])();
}
