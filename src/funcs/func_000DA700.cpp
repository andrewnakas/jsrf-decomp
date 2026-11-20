/* sym: ?func_00011C90_1@Object_000DA3E0@@UAEXXZ = 0x000DA700 */
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

// The child of Node whose table is at 0x1CE658.
struct Object_000DA3E0 : Node {
    char unknown_40[4];
    int state;

    void func_000DA3E0();
    virtual void func_00011C90_1();
};

// Overrides Node's slot 2: runs func_000DA3E0 in state 0.
void Object_000DA3E0::func_00011C90_1()
{
    if (state == 0) {
        func_000DA3E0();
    }
}
