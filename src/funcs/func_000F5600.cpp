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

// The child of Node whose table is at 0x1CF220 (destructor func_000F60C0; a second base sits further on, not
// declared here). Slots 16 to 31 of its table; the class of the table at 0x1CEAC0 derives from it.
struct Object_000F55E0 : Node {
    virtual void func_000F51A0();
    virtual void func_000F5310();
    virtual void func_000F5380();
    virtual void func_000F53E0();
    virtual void func_000F63E0();
    virtual void func_000F6480();
    virtual void func_000F6500();
    virtual void func_000F54C0();
    virtual void func_000F5510();
    virtual void func_000F5550();
    virtual void func_000F55A0();
    virtual void func_000F6580();
    virtual void func_000F55E0();
    virtual void func_000F6620();
    virtual void func_000F5600();

    char unknown_40[0x7c];
    int state;
    char unknown_c0[0x18];
    int timer;
    char unknown_dc[0x94];
    int mode;
};

// Slot 30 of the vtable at data_001CF220 (stored by func_000F5E70 and func_000F60C0), which the class at
// 0x1CEAC0 inherits: when the mode at 0x170 is 2, state 7 and the timer at 0xd8 = 0.
void Object_000F55E0::func_000F5600()
{
    if (mode == 2) {
        state = 7;
        timer = 0;
    }
}
