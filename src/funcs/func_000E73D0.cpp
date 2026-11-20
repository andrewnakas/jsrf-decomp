/* sym: ??0Object_000E6E80@@QAE@PAUNode@@HIHHH@Z = 0x000E69E0 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Node {
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

// The child of Node whose table is at 0x1CEDA0 (0x5b0 bytes; constructor func_000E69E0).
struct Object_000E6E80 : Node {
    Object_000E6E80(Node *owner, int id, unsigned int flags, int first, int second, int third);
    virtual ~Object_000E6E80();

    char unknown_044[0x56c];
};

// Builds an Object_000E6E80 under object 9 (id -1, flags 0x104) with the three values it is given.
void func_000E73D0(int first, int second, int third)
{
    Node *owner = (Node *)data_0022FCE0->func_000128C0(9);
    new Object_000E6E80(owner, -1, 0x104, first, second, third);
}
