/* sym: ?func_00011C90@Object_000B9960@@UAEXXZ = 0x000B9960 */
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

// The child of Node whose table is at 0x1CD998 (destructor func_000B8610).
struct Object_000B9960 : Node {
    char unknown_040[0x1e8];
    unsigned int flags_228;

    void func_000B8A60();
    void func_000B9270();
    virtual void func_00011C90();
};

// Overrides Node's slot 1: picks one of two routines by the top bit of the flags at 0x228.
void Object_000B9960::func_00011C90()
{
    if (!(flags_228 & 0x80000000)) {
        func_000B8A60();
    } else {
        func_000B9270();
    }
}
