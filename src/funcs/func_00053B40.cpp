void func_00024620(unsigned int colour, float speed);

struct Game {
    void func_000127C0(int first, int second);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    int func_000149D0_1();
    void func_00039C70();
    void func_0003AE20(int kind);
    void func_0003AEA0(int kind);
};

extern Object_00039BE0 data_001EFFB0;

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

struct Object_0004ABA0 : Node {
    char unknown_044[0x18];
    int state;

    void func_0004D880();
    void func_00053B40();
};

// State handler 101 of the tables at 0x1F9888 and 0x1F9C48: resets 0x1EFFB0 (func_00039C70, func_0003AE20 (1),
// func_0003AEA0 (1)); when its word at +4 is 9, fades with func_00024620 and goes to state 0x66, otherwise passes the
// word to the game, takes the object out and runs func_0004D880.
void Object_0004ABA0::func_00053B40()
{
    data_001EFFB0.func_00039C70();
    data_001EFFB0.func_0003AE20(1);
    data_001EFFB0.func_0003AEA0(1);
    if (data_001EFFB0.func_000149D0_1() == 9) {
        func_00024620(0xff000000, 0.016666668f);
        data_0022FCE0->func_000127C0(4, -1);
        data_0022FCE0->func_000127C0(0x199, 0x34);
        state = 0x66;
        return;
    }
    data_0022FCE0->func_000127C0(2, data_001EFFB0.func_000149D0_1());
    data_0022FCE0->func_000127C0(4, 0x60);
    if (this) {
        func_00011BE0(this);
        func_00011C20(child);
    }
    func_0004D880();
}
