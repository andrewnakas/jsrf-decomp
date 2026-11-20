/* sym: ??0Object_0004EF90@@QAE@PAUNode@@HI@Z = 0x0004ECD0 */
int func_000256C0(unsigned int index, int argument);
void func_0004EAF0();

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

// The class whose table is at 0x1CAAF8 (constructor 0x4ECD0, destructor 0x4EF00; 0xb0 bytes).
struct Object_0004EF90 : Node {
    Object_0004EF90(Node *owner, int id, unsigned int flags);
    virtual ~Object_0004EF90();

    char unknown_44[0x6c];
};

struct Object_0007C250 : Node {
    int unknown_44;
    int state;

    void func_0007D320();
};

// State handler 53 of the table at 0x20D2B8: once func_000256C0 (0x15, 1) says so, state 0x36, func_000127C0 of the
// game for (0x1cb, 1), (8, 0), (0xb, 1) and (0x19a, 1), func_0004EAF0 and a new Object_0004EF90 under this object
// (id 8).
void Object_0007C250::func_0007D320()
{
    if (func_000256C0(0x15, 1)) {
        state = 0x36;
        data_0022FCE0->func_000127C0(0x1cb, 1);
        data_0022FCE0->func_000127C0(8, 0);
        data_0022FCE0->func_000127C0(0xb, 1);
        data_0022FCE0->func_000127C0(0x19a, 1);
        func_0004EAF0();
        new Object_0004EF90(this, 8, 0);
    }
}
