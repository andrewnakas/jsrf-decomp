struct Motion_0005F060;

int func_0005E7B0(void *target, int first, int second, int third, int fourth);
void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);
void func_0005EC20(void *target, int first, int second, int third, int fourth, Motion_0005F060 *blend,
                   float blendTime, float weight);

// The model's skeleton (its target at 0x8).
struct Skeleton_000D5170 {
    char unknown_00[8];
    void *target;
};

// The holder of the model at 0xef4.
struct Holder_000D5170 {
    Skeleton_000D5170 *skeleton;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE450 (constructor func_000D27F0).
struct Object_000D27F0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D27F0();

    void func_000D5170();

    void *owner;
    int state;
    char unknown_00c[0xee8];
    Holder_000D5170 *holder;
    char unknown_ef8[0xc];
    Motion_0005F060 *motion_f04;
    Motion_0005F060 *blend_f08;
    Motion_0005F060 *blend_f0c;
    Motion_0005F060 *motion_f10;
    Motion_0005F060 *motion_f14;
    char unknown_f18[4];
    float time_f1c;
    float time_f20;
    float time_f24;
    float weight;
    char unknown_f2c[4];
    int mode;
    int previous;
    int value_f38;
    int blending;
};

// The handlers by mode (0xf30).
extern void (Object_000D27F0::*data_00216DC8[])();

// When the mode at 0xf30 changes, clears the motion state (0xf38, the times at 0xf1c and 0xf20, the blends at 0xf08
// and 0xf0c, the weight at 0xf28) with blending (0xf3c) on; runs the mode's handler from 0x216DC8; then poses the
// model at 0xef4 with the motion at 0xf14 (0xf10 without blending) blended into the one at 0xf04 (time 0xf1c),
// through the one at 0xf08 when set (func_0005EC20), blends in the one at 0xf0c when set, and when blending, the one
// at 0xf10 into 0xf14 by a quarter.
void Object_000D27F0::func_000D5170()
{
    if (mode != previous) {
        value_f38 = 0;
        previous = mode;
        time_f20 = 0;
        time_f1c = 0;
        blend_f08 = 0;
        blend_f0c = 0;
        blending = 1;
        weight = 0;
    }
    (this->*data_00216DC8[mode])();
    Motion_0005F060 *motion;
    if (blending) {
        motion = motion_f14;
    } else {
        motion = motion_f10;
    }
    if (blend_f08) {
        func_0005EC20(holder->skeleton->target, (int)motion, 0, (int)motion_f04, *(int *)&time_f1c, blend_f08, time_f20,
                      weight);
    } else {
        func_0005E7B0(holder->skeleton->target, (int)motion, 0, (int)motion_f04, *(int *)&time_f1c);
    }
    if (blend_f0c) {
        func_0005EAF0(holder->skeleton->target, motion, 0.0f, motion, 0.0f, blend_f0c, time_f24);
    }
    if (blending) {
        func_0005EC20(holder->skeleton->target, (int)motion_f10, 0, (int)motion_f10, 0, motion_f14, 0.0f, 0.25f);
    }
}
