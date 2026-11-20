/* sym: ?func_000FDDC0@Object_000FB530@@UAEXXZ = 0x000FB530 */
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

// The child of Node whose table is at 0x1D1BA8 (destructor func_000FD9B0); slot 16 is func_000FDDC0.
struct Object_000FDDC0 : Node {
    virtual void func_000FDDC0();
};

// The child of that class whose table is at 0x1D1B20 (destructor func_000FB300).
struct Object_000FB530 : Object_000FDDC0 {
    virtual void func_000FDDC0();

    char unknown_40[0x40];
    unsigned int flags;
    char unknown_84[0x10];
    int mode;
};

// Overrides slot 16: unless in mode 8 at 0x94, sets flag 0x8000000 at 0x80.
void Object_000FB530::func_000FDDC0()
{
    if (mode != 8) {
        flags |= 0x8000000;
    }
}
