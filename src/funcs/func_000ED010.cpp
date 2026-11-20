struct Motion_0005F060;

void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);
void func_0005EC20(void *target, int first, int second, int third, int fourth, Motion_0005F060 *blend,
                   float blendTime, float weight);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

// A model of the bank (its target at 0x8).
struct Model_000EA3B0 {
    char unknown_00[8];
    void *target;
};

// The motion set at 0x118.
struct MotionSet_000EA3B0 {
    char unknown_00[0x18];
    Motion_0005F060 *motion_18;
    char unknown_1c[0x30];
    Motion_0005F060 *motion_4c;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The object func_000EA3B0 builds (0x1f4 bytes; table 0x1CEE78).
struct Object_000EA3B0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000EA3B0();

    void func_000ED010();

    char unknown_004[0x10c];
    Model_000EA3B0 **models;
    char unknown_114[4];
    MotionSet_000EA3B0 *motionSet;
    Motion_0005F060 *motion_11c;
    Motion_0005F060 *blend_120;
    Motion_0005F060 *blend_124;
    Motion_0005F060 *motion_128;
    float time_12c;
    float time_130;
    float time_134;
    float time_138;
    float time_13c;
    float weight_140;
    int mode;
    int previous;
    int phase;
};

// The class the handlers at 0x258560 belong to (as func_000ED190.cpp names it); its member pointers are eight
// bytes (a function and a this adjustment), which takes a second base.
struct Link_000ED010 {
};

struct Object_000E7F50 : Object_000CC600, Link_000ED010 {
};

// The handlers run by the mode at 0x144 (filled in by the dynamic initializer func_0018C150).
extern void (Object_000E7F50::*data_00258560[])();

// Runs the handler of the mode at 0x144 (a new mode starts at phase 0 with no blend at 0x120). Unless the mode is 6,
// poses the first model's target: the motion at 0x128 with the one at 0x11c (time 0x12c), blended with 0x120 (time
// 0x130, weight 0x140) when there is one, then with the set's motion 0x18 (time 0x138), and with 0x124 (time 0x134)
// when there is one; then advances the set's motions 0x18 and 0x4c at half speed.
void Object_000EA3B0::func_000ED010()
{
    int current = mode;
    if (current != previous) {
        phase = 0;
        previous = current;
        blend_120 = 0;
    }
    (((Object_000E7F50 *)this)->*data_00258560[current])();
    if (mode == 6) {
        return;
    }
    if (blend_120) {
        func_0005EC20(models[0]->target, (int)motion_128, 0, (int)motion_11c, *(int *)&time_12c, blend_120, time_130,
                      weight_140);
        func_0005EAF0(models[0]->target, motion_128, 0.0f, motion_128, 0.0f, motionSet->motion_18, time_138);
    } else {
        func_0005EAF0(models[0]->target, motion_128, 0.0f, motion_11c, time_12c, motionSet->motion_18, time_138);
    }
    if (blend_124) {
        func_0005EAF0(models[0]->target, motion_128, 0.0f, motion_128, 0.0f, blend_124, time_134);
    }
    func_0005E030(motionSet->motion_18, &time_138, 0.5f, 0);
    func_0005E030(motionSet->motion_4c, &time_13c, 0.5f, 0);
}
