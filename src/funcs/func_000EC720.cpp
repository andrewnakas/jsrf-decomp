struct Motion_0005F060;

void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int flags);

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

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The model's skeleton (its target at 0x8).
struct Skeleton_000EC720 {
    char unknown_00[8];
    void *target;
};

// The model at 0x13c.
struct Model_000EC720 {
    Skeleton_000EC720 *skeleton;
};

// The motion set at 0x144.
struct MotionSet_000EC720 {
    char unknown_00[0x18];
    Motion_0005F060 *motion_18;
    char unknown_1c[0x30];
    Motion_0005F060 *motion_4c;
};

// The class whose tables are at 0x1CEF20 (Node) and 0x1CEF18 (Object_000C60C0 at +0x44).
struct Object_000ECB50 : Node, Object_000C60C0 {
    virtual ~Object_000ECB50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000EC720();

    char unknown_048[0x48];
    unsigned int flags_90;
    char unknown_094[0xa8];
    Model_000EC720 *model;
    char unknown_140[4];
    MotionSet_000EC720 *set;
    Motion_0005F060 *motion_148;
    Motion_0005F060 *blend_14c;
    Motion_0005F060 *motion_150;
    float time_154;
    float blend_158;
    float time_15c;
    float time_160;
};

// Blends the motion at 0x150 into the one at 0x148 (time 0x154) with the set's motion 0x18 (time 0x15c) on the
// model at 0x13c, then the one at 0x14c (time 0x158) when set; unless the flag 0x4000000 is set at 0x90, steps the
// set's motions 0x18 and 0x4c by half a frame (times 0x15c and 0x160).
void Object_000ECB50::func_000EC720()
{
    func_0005EAF0(model->skeleton->target, motion_150, 0.0f, motion_148, time_154, set->motion_18, time_15c);
    if (blend_14c) {
        func_0005EAF0(model->skeleton->target, motion_150, 0.0f, motion_150, 0.0f, blend_14c, blend_158);
    }
    if (!(flags_90 & 0x4000000)) {
        func_0005E030(set->motion_18, &time_15c, 0.5f, 0);
        func_0005E030(set->motion_4c, &time_160, 0.5f, 0);
    }
}
