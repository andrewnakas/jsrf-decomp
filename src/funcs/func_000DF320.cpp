struct Motion_0005F060;

void func_0005E7B0(void *target, int first, int second, int third, int fourth);
void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);
void func_0005EC20(void *target, int first, int second, int third, int fourth, Motion_0005F060 *blend,
                   float blendTime, float weight);

// The model's skeleton (its target at 0x8).
struct Skeleton_000DF320 {
    char unknown_00[8];
    void *target;
};

// The holder of the model at 0x180.
struct Holder_000DF320 {
    Skeleton_000DF320 *skeleton;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE320 (constructor func_000CC620, destructor func_000CC680).
struct Object_000CCE00 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CCE00();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CBF20();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();
    virtual void func_000CC020();

    Object_000C5B50 *owner;
    char unknown_08[0x2c];
};

// The class whose table is at 0x1CE7B8 (constructor func_000DCBC0, which runs func_000CC620 first); slots 8 and 16
// stay Object_000CCE00's.
struct Object_000DCBC0 : Object_000CCE00 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000DCBC0();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();

    void func_000DF320();

    char unknown_034[0x14c];
    Holder_000DF320 *holder;
    char unknown_184[0x10];
    Motion_0005F060 *motion_194;
    Motion_0005F060 *blend_198;
    Motion_0005F060 *blend_19c;
    Motion_0005F060 *motion_1a0;
    Motion_0005F060 *motion_1a4;
    char unknown_1a8[4];
    float time_1ac;
    float time_1b0;
    float time_1b4;
    float weight;
    char unknown_1bc[4];
    int mode;
    int previous;
    int value_1c8;
};

// The handlers by mode (0x1c0).
extern void (Object_000DCBC0::*data_00217AB8[])();

// Unless the owner has the flag 0x100: when the mode at 0x1c0 changes, clears the motion state (0x1c8, the times at
// 0x1ac and 0x1b0, the blends at 0x198 and 0x19c); runs the mode's handler from 0x217AB8; then poses the model at
// 0x180 with the motion at 0x1a4 blended into the one at 0x194 (time 0x1ac), through the one at 0x198 when set
// (func_0005EC20), blends in the one at 0x19c when set, and finally the one at 0x1a0 into 0x1a4 by a quarter.
void Object_000DCBC0::func_000DF320()
{
    if (owner->flags & 0x100) {
        return;
    }
    if (mode != previous) {
        value_1c8 = 0;
        previous = mode;
        time_1b0 = 0;
        time_1ac = 0;
        blend_198 = 0;
        blend_19c = 0;
    }
    (this->*data_00217AB8[mode])();
    if (blend_198) {
        func_0005EC20(holder->skeleton->target, (int)motion_1a4, 0, (int)motion_194, *(int *)&time_1ac, blend_198,
                      time_1b0, weight);
    } else {
        func_0005E7B0(holder->skeleton->target, (int)motion_1a4, 0, (int)motion_194, *(int *)&time_1ac);
    }
    if (blend_19c) {
        func_0005EAF0(holder->skeleton->target, motion_1a4, 0.0f, motion_1a4, 0.0f, blend_19c, time_1b4);
    }
    func_0005EC20(holder->skeleton->target, (int)motion_1a0, 0, (int)motion_1a0, 0, motion_1a4, 0.0f, 0.25f);
}
