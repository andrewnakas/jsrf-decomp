struct Game {
    void func_000129C0(int argument);
};

extern Game *data_0022FCE0;

int func_000256C0(unsigned int index, int argument);

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

void func_0007E7D0(Node *owner);

struct Object_0007C250 : Node {
    int step;
    int state;

    void func_0007C0D0();
};

// State handler 7 of the table at 0x20D2B8: once func_000256C0 (0x16, 0) says so, creates object 0x1dda under this
// one (func_0007E7D0), runs func_000129C0 of the game (1) and moves to state 8.
void Object_0007C250::func_0007C0D0()
{
    if (func_000256C0(0x16, 0)) {
        func_0007E7D0(this);
        data_0022FCE0->func_000129C0(1);
        state = 8;
    }
}
