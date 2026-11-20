/* sym: ??0Object_00024240@@QAE@PAUNode@@HIH@Z = 0x00024240 */
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

// The node class whose table is at 0x1C4CD0 (constructor 0x24240, destructor 0x24330; 0x64 bytes).
struct Object_00024240 : Node {
    Object_00024240(Node *owner, int id, unsigned int flags, int value);
    virtual ~Object_00024240();

    int unknown_44[8];
};

struct Stage_00056540 {
    char unknown_00[0x14];
    int unknown_14;
};

struct Object_0004ABA0 : Node {
    char unknown_044[0x18];
    int state;
    char unknown_060[0xf58];
    Stage_00056540 *stage;

    void func_0004D880();
    void func_000524E0();
};

// State handler 18 of the table at 0x1F9888: creates an Object_00024240 under this object (id 0x1ddb, flags 0x20, the
// stage's +0x14), runs func_0004D880 and moves to state 0x13.
void Object_0004ABA0::func_000524E0()
{
    new Object_00024240(this, 0x1ddb, 0x20, stage->unknown_14);
    func_0004D880();
    state = 0x13;
}
