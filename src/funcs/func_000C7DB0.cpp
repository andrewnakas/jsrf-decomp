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

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240; a second base with the table at
// 0x1CE1C0 sits at 0x44, not declared here). Slots 16 to 32 of its table.
struct Object_000C7910 : Node {
    virtual void func_000C7910();
    virtual void func_000D47F0();
    virtual void func_000C7A70();
    virtual void func_000C7AB0();
    virtual void func_000C7B30();
    virtual void func_000C87D0();
    virtual void func_000C7B90();
    virtual void func_000C7BB0();
    virtual void func_000C7C70();
    virtual void func_000C8870();
    virtual void func_000C88E0();
    virtual void func_000C7CD0();
    virtual void func_000C7CF0();
    virtual void func_000C7D40();
    virtual void func_000C8980();
    virtual void func_000C89F0();
    virtual void func_000C7DB0();

    char unknown_40[0x50];
    unsigned int flags;
    char unknown_94[0x28];
    int state;
    char unknown_c0[0x2c];
    int timer;
    char unknown_f0[0xcc];
    int value_1bc;
    char unknown_1c0[4];
    int mode_1c4;
    char unknown_1c8[0x204];
    int mode_3cc;
};

// Slot 32 (and slot 36, the same code): in mode 2 at 0x1c4, state 17 and the timer at 0xec cleared.
void Object_000C7910::func_000C7DB0()
{
    if (mode_1c4 == 2) {
        state = 17;
        timer = 0;
    }
}
