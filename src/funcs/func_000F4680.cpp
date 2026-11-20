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

// The class of the member-function table at 0x21b2dc (func_000F4140 is entry 4).
struct Object_000F4140 : Node {
    char unknown_040[4];
    int state;
    char unknown_048[0x84];
    int value_cc;

    void func_000F41C0();
    void func_000F4280();
    int func_000F4570();
    void func_000F4680();
};

// Entry 1 of that table: when func_000F4570 reports true, func_000F4280, state 2 at 0x44 and 0 at 0xcc;
// otherwise func_000F41C0.
void Object_000F4140::func_000F4680()
{
    if (func_000F4570()) {
        func_000F4280();
        state = 2;
        value_cc = 0;
    } else {
        func_000F41C0();
    }
}
