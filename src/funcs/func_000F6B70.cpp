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

struct Motion_0005F060;

// The motion set at 0x138: motions by index.
struct MotionSet_000F55E0 {
    Motion_0005F060 *motions[64];
};

// The object at 0x130.
struct Model_000F55E0 {
    char unknown_00[8];
    void *value_08;
};

int func_0005E030(Motion_0005F060 *motion, float *time, float step, int hold);
void func_0005E7B0(void *first, int second, int third, int fourth, int fifth);

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

    char unknown_040[0xf0];
    Model_000F55E0 *model;
    char unknown_134[0x4];
    MotionSet_000F55E0 *motionSet;
    Motion_0005F060 *motion;
    char unknown_140[0x8];
    int value_148;
    char unknown_14c[0x4];
    int value_150;
    float time;
    char unknown_158[0x18];
    int phase;
};

// Slot 36: in phase 0 (at 0x170), calls func_0005E7B0 with the value at 8 of the object at 0x130 and the values at
// 0x150 and 0x148, then starts motion 15 of the set at 0x138 (time 0, next phase); afterwards steps it by 0.5
// (func_0005E030, hold 0).
void Object_000F55E0::func_000F6B70()
{
    if (!phase) {
        func_0005E7B0(model->value_08, value_150, 0, value_148, 0);
        motion = motionSet->motions[15];
        time = 0.0f;
        phase++;
        return;
    }
    func_0005E030(motion, &time, 0.5f, 0);
}
