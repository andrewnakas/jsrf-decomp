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

struct Vector3 {
    float x;
    float y;
    float z;
};

// The parameters at 0x11c.
struct Params_000F55E0 {
    char unknown_00[0x10];
    int interval;
};

// The object at data_00257CE4; its position is at 0x7c.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

float __fastcall func_0014CB60(const Vector3 *from, const Vector3 *to);

// The child of Node whose table is at 0x1CF220 (constructor func_000F5E70, destructor func_000F60C0); slots 16 to
// 52 of its table. The class of the table at 0x1CEAC0 derives from it.
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
    virtual void func_000F5620();
    virtual void func_000F66C0();
    virtual void func_000F6700();
    virtual void func_000F5640();
    virtual void func_000F6770();
    virtual void func_000F6B70();
    virtual void func_000F6BF0();
    virtual void func_000F6C40();
    virtual void func_000F6C90();
    virtual void func_000F6D60();
    virtual void func_000F6DD0();
    virtual void func_000F6E30();
    virtual void func_000F6E90();
    virtual void func_000F6F00();
    virtual void func_000F6F70();
    virtual void func_000F6FE0();
    virtual void func_000F7050();
    virtual void func_000F70E0();
    virtual void func_000F7120();
    virtual void func_000F7180();
    virtual void func_000F71D0();
    virtual void func_000F7230();

    void func_000F56F0();
    void func_000F5760(int argument);
    void func_000F5D70(int argument);

    char unknown_040[0x8];
    Vector3 position;
    char unknown_054[0x68];
    int state;
    char unknown_0c0[0x18];
    int timer;
    char unknown_0dc[0x40];
    Params_000F55E0 *params;
    char unknown_120[0x48];
    int mode;
};

// Slot 21: func_000F56F0; counts the timer at 0xd8 down; at 0 calls func_000F5760(1) and restarts it from the interval
// at 0x10 of the parameters at 0x11c. Then func_000F5D70(1); farther than 150 (x/z) from the position at 0x7c of
// data_00257CE4, state 6 and mode 4 (0x168); then slot 35.
void Object_000F55E0::func_000F6480()
{
    func_000F56F0();
    if (--timer <= 0) {
        func_000F5760(1);
        timer = params->interval;
    }
    func_000F5D70(1);
    if (func_0014CB60(&position, &data_00257CE4->position) > 150.0f) {
        state = 6;
        mode = 4;
    }
    func_000F6770();
}
