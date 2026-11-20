struct Game {
    void func_000127C0(int first, int second);
};

extern Game *data_0022FCE0;

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
    void func_0004D880();
    void func_00053B10();
};

// State handler 0x64 of the tables at 0x1F9888 and 0x1F9C48: runs func_0004D880, func_000127C0 of the game (4, -1)
// and takes the object out.
void Object_0004ABA0::func_00053B10()
{
    func_0004D880();
    data_0022FCE0->func_000127C0(4, -1);
    if (this) {
        func_00011BE0(this);
        func_00011C20(child);
    }
}
