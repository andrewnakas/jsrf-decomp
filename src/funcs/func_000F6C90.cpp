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

int func_0005E030(Motion_0005F060 *motion, float *time, float step, int hold);

struct Object_000C1440 {
    int func_000C1440(int from, int to);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1440.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;

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

    char unknown_040[0x18];
    int angle;
    char unknown_05c[0x98];
    int heading;
    char unknown_0f8[0x40];
    MotionSet_000F55E0 *motionSet;
    Motion_0005F060 *motion;
    char unknown_140[0x4];
    Motion_0005F060 *turnMotion;
    char unknown_148[0xc];
    float time;
    char unknown_158[0x4];
    float lastTime;
    char unknown_160[0x10];
    int phase;
    char unknown_174[0x4];
    float turnTime;
};

// Slot 39: in phase 0 (at 0x170) starts motion 42 of the set at 0x138 (time 0, next phase); afterwards steps it by 0.5
// (func_0005E030, hold 0) and, by the sign of the turn from the heading at 0xf4 to the angle at 0x58 (func_000C1440),
// plays motion 50 or 49 at 0x144 (keeping its last time at 0x15c), or clears 0x144 when there is no turn.
void Object_000F55E0::func_000F6C90()
{
    if (!phase) {
        motion = motionSet->motions[42];
        time = 0.0f;
        phase = 1;
        return;
    }
    func_0005E030(motion, &time, 0.5f, 0);
    int turn = data_00257CE8->func_000C1440(heading, angle);
    if (turn) {
        if (turn >= 0) {
            turnMotion = motionSet->motions[50];
        } else {
            turnMotion = motionSet->motions[49];
        }
        lastTime = turnTime;
        func_0005E030(turnMotion, &turnTime, 0.5f, 0);
    } else {
        turnMotion = 0;
    }
}
