/* sym: ?func_00011C90_1@Object_000B9960@@UAEXXZ = 0x000B9980 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD998).
struct Object_000B9960 : Node {
    virtual ~Object_000B9960();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[8];
    int state;
    int value_4c;
    int value_50;
    int value_54;
    char unknown_058[0x1d0];
    unsigned int flags_228;

    void func_000B94B0();
    void func_000B97E0();
};

// Overrides slot 2: with flag 0x400000 at 0x228, state 3 at 0x48 and nothing at 0x50, state 7; then func_000B97E0
// when the top bit of 0x228 is set, else func_000B94B0; clears 0x4c, 0x50 and 0x54.
void Object_000B9960::func_00011C90_1()
{
    if ((flags_228 & 0x400000) && state == 3 && !value_50) {
        state = 7;
    }
    if (!(flags_228 & 0x80000000)) {
        func_000B94B0();
    } else {
        func_000B97E0();
    }
    value_4c = 0;
    value_50 = 0;
    value_54 = 0;
}
