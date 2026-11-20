struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int flags);
void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);
void func_0005EC20(void *target, int first, int second, int third, int fourth, Motion_0005F060 *blend,
                   float blendTime, float weight);
float func_0014C850(float value, float limit);
float func_0014C870(float value, float power);

// The model's skeleton (its target at 0x8).
struct Skeleton_000E4250 {
    char unknown_00[8];
    void *target;
};

// The holder of the model at 0x164.
struct Holder_000E4250 {
    Skeleton_000E4250 *skeleton;
};

// The motion set at 0x168.
struct Set_000E4250 {
    Motion_0005F060 *motions[4];
};

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


// The class whose tables are at 0x1CED20 (Node) and the Object_000C60C0 part at +0x44.
struct Object_000E45D0 : Node, Object_000C60C0 {
    virtual ~Object_000E45D0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000E4250();

    char unknown_048[0x48];
    unsigned int flags_90;
    char unknown_094[0x30];
    int count_c4;
    int count_c8;
    char unknown_0cc[0x98];
    Holder_000E4250 *holder;
    Set_000E4250 *set;
    Motion_0005F060 *motion_16c;
    Motion_0005F060 *motion_170;
    float time;
    float weight;
};

// Without the flag 0x2000 at 0x90: blends motion 0 of the set at 0x168 into the one at 0x16c, at a time growing with
// the count at 0xc4, with motion 1 weighted by (1 - count 0xc8 / 8192) squared (func_0014C850, func_0014C870), and steps
// motion 2 by half a frame (time 0x174); with the flag, raises the weight at 0x178 by 1/60 up to 1 and blends motion
// 3 by it into the motions at 0x16c and 0x170 (func_0005EC20).
void Object_000E45D0::func_000E4250()
{
    if (!(flags_90 & 0x2000)) {
        float speed = count_c4 * (1.0f / 32768.0f) + 1.0f;
        float blend = 1.0f - count_c8 * (1.0f / 8192.0f);
        blend = func_0014C850(blend, 0.0f);
        blend = func_0014C870(blend, 2.0f);
        func_0005EAF0(holder->skeleton->target, motion_16c, 0.0f, set->motions[0], speed, set->motions[1], blend);
        func_0005E030(set->motions[2], &time, 0.5f, 0);
    } else if (weight < 1.0f) {
        weight += 1.0f / 60.0f;
        func_0005EC20(holder->skeleton->target, (int)motion_16c, 0, (int)motion_170, 0, set->motions[3], 0.0f, weight);
    }
}
