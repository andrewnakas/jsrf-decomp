/* sym: ??0Object_0004EF90@@QAE@PAUNode@@HI@Z = 0x0004ECD0 */
void func_0004EAF0();
void func_00024620(unsigned int color, float step);

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

    void func_0007D460();
};

// State handler 49 of the table at 0x20D2B8: state 0x32, func_000127C0 of the game for (2, 9), (3, 0x60), (0xb, 0)
// and (0x19a, 1), func_0004EAF0, a new Object_0004EF90 under this object (id 8) and a fade over 60 frames
// (func_00024620).
void Object_0007C250::func_0007D460()
{
    state = 0x32;
    data_0022FCE0->func_000127C0(2, 9);
    data_0022FCE0->func_000127C0(3, 0x60);
    data_0022FCE0->func_000127C0(0xb, 0);
    data_0022FCE0->func_000127C0(0x19a, 1);
    func_0004EAF0();
    new Object_0004EF90(this, 8, 0);
    func_00024620(0, 1.0f / 60.0f);
}
