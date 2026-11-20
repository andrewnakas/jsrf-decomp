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
    int unknown_40;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The child of Node whose table is at 0x1CF220 (constructor func_000F5E70, destructor func_000F60C0); slots 16 to
// 52 of its table. The class of the table at 0x1CEAC0 derives from it. The second base sits at 0x44 (tables 0x1CE1B8,
// then 0x1CF214).
struct Object_000F55E0 : Node, Object_000C60C0 {
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

    void func_000F5930();

    Vector3 position;
    char unknown_054[0x3c];
    unsigned int flags_90;
    char unknown_094[0x8];
    int value_9c;
    char unknown_0a0[0x1c];
    int state;
    char unknown_0c0[0x18];
    int timer;
    char unknown_0dc[0x28];
    float value_104;
    char unknown_108[0x68];
    int phase;
};

// Slot 33: func_000F5930; then, without flag 0x80 at 0x90 or when the value at 0x104 is more than 200 above y at 0x4c:
// flag 0x2000, state 18, phase 2 (0x170), slot 1 of the second base, the timer at 0xd8 back to 0 and 1 at 0x9c.
void Object_000F55E0::func_000F6700()
{
    func_000F5930();
    if (!(flags_90 & 0x80) || value_104 - position.y > 200.0f) {
        flags_90 |= 0x2000;
        state = 18;
        phase = 2;
        func_000C60C0();
        timer = 0;
        value_9c = 1;
    }
}
