/* sym: ??0Object_00071040@@QAE@PAUNode@@HIH@Z = 0x00070E30 */
int func_000256C0(unsigned int index, int argument);

struct Game {
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_000667D0 {
    void func_000667D0();
};

extern Object_000667D0 *data_00251F24;

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

void func_00075DE0(Node *owner, int value);

// The class whose table is at 0x1CCA80 (constructor 0x70E30, destructor 0x71040; 0x520 bytes).
struct Object_00071040 : Node {
    Object_00071040(Node *owner, int id, unsigned int flags, int value);
    virtual ~Object_00071040();

    char unknown_044[0x4dc];
};

struct Object_0007C250 : Node {
    int unknown_44;
    int state;

    void func_0007C720();
};

// State handler 21 of the table at 0x20D2B8: unless 0x1a8 is 1 in the game, once func_000256C0 (10, 0) says so,
// func_00075DE0 (this, 1); otherwise, once func_000256C0 (0x12, 1) says so, a new Object_00071040 under this object
// (id 0x128a); then state 0x16 and func_000667D0 of the object at 0x251F24.
void Object_0007C250::func_0007C720()
{
    switch (data_0022FCE0->func_000127E0(0x1a8)) {
    case 1:
        if (!func_000256C0(0x12, 1))
            return;
        new Object_00071040(this, 0x128a, 1, 1);
        break;
    default:
        if (!func_000256C0(10, 0))
            return;
        func_00075DE0(this, 1);
        break;
    }
    state = 0x16;
    data_00251F24->func_000667D0();
}
