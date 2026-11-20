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

void func_000C6950(void *first, float *second);

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

    char unknown_040[0x8];
    Vector3 position;
    char unknown_054[0xc];
    Vector3 velocity;
    char unknown_06c[0x24];
    unsigned int flags_90;
    char unknown_094[0xc];
    int value_a0;
    char unknown_0a4[0x18];
    int state;
    char unknown_0c0[0xc];
    Vector3 value_cc;
    char unknown_0d8[0x10];
    float scaleX;
    float value_ec;
    float scaleZ;
    char unknown_0f4[0x74];
    int mode;
    char unknown_16c[0x4];
    int phase;
};

// Slot 29: moves the vector at 0xcc by the speed at 0x60 (scaled by 0xe8 and 0xf0 on x and z) and 0x64 on y; in
// phase 2 (0x170) without flag 0x80: flag 0x8000, state 14, mode 10 (0x168), the speed at 0x60 cleared, and the first
// time (0xa0) func_000C6950 on the fields at 0x48 and 0xe8.
void Object_000F55E0::func_000F6620()
{
    value_cc.x += velocity.x * scaleX;
    value_cc.y += velocity.y;
    value_cc.z += scaleZ * velocity.x;
    if (phase == 2 && !(flags_90 & 0x80)) {
        flags_90 |= 0x8000;
        state = 14;
        mode = 10;
        velocity.x = 0.0f;
        if (!value_a0) {
            func_000C6950(&position, &scaleX);
            value_a0 = 1;
        }
    }
}
