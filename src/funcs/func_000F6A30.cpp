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

struct Motion_0005F060;

int func_0005E7B0(void *target, int first, int second, int third, int fourth);
void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);
void func_0005EC20(void *target, int first, int second, int third, int fourth, Motion_0005F060 *blend,
                   float blendTime, float weight);

// The skeleton at 0x130: its pose target at 0x8.
struct Object_00047470 {
    char unknown_00[8];
    void *target;
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The child of Node whose table is at 0x1CF220 (constructor func_000F5E70, destructor func_000F60C0). The class of the
// table at 0x1CEAC0 derives from it. The second base sits at 0x44 (tables 0x1CE1B8, then 0x1CF214).
struct Object_000F55E0 : Node, Object_000C60C0 {
    void func_000F6A30();

    char unknown_048[0x48];
    unsigned int bits;
    char unknown_094[0x9c];
    Object_00047470 *skeleton;
    char unknown_134[8];
    int value_13c;
    Motion_0005F060 *blend;
    Motion_0005F060 *overlay;
    Motion_0005F060 *motion;
    Motion_0005F060 *nextMotion;
    char unknown_150[4];
    int value_154;
    float blendTime;
    float overlayTime;
    float weight;
    char unknown_164[4];
    int animation;
    int current;
    int value_170;
    int changing;
};

// The animation handlers (member-function pointers with this adjustment) by the animation at 0x168.
extern void (Object_000F55E0::*data_00258778[])();

// Unless 0x90 has bit 8: a new animation (0x168 against 0x16c) clears 0x170 and both blends and sets 0x174; runs
// the animation's handler of data_00258778, then poses the skeleton with the motion at 0x14c (while 0x174 is set) or
// 0x148, blended with the motion at 0x140 (func_0005EC20) or not (func_0005E7B0), the one at 0x144 laid over it
// (func_0005EAF0), and while changing, 0x148 into 0x14c by 0.33 (func_0005EC20).
void Object_000F55E0::func_000F6A30()
{
    if (bits & 0x100) {
        return;
    }
    if (animation != current) {
        value_170 = 0;
        current = animation;
        blend = 0;
        overlay = 0;
        changing = 1;
    }
    (this->*data_00258778[animation])();
    Motion_0005F060 *pose;
    if (changing) {
        pose = nextMotion;
    } else {
        pose = motion;
    }
    if (blend) {
        func_0005EC20(skeleton->target, (int)pose, 0, value_13c, value_154, blend, blendTime, weight);
    } else {
        func_0005E7B0(skeleton->target, (int)pose, 0, value_13c, value_154);
    }
    if (overlay) {
        func_0005EAF0(skeleton->target, pose, 0.0f, pose, 0.0f, overlay, overlayTime);
    }
    if (changing) {
        func_0005EC20(skeleton->target, (int)motion, 0, (int)motion, 0, nextMotion, 0.0f, 0.33f);
    }
}
