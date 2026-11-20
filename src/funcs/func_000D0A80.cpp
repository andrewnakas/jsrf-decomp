struct Motion_0005F060;

int func_0005E7B0(void *target, int first, int second, int third, int fourth);
void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);
void func_0005EC20(void *target, int first, int second, int third, int fourth, Motion_0005F060 *blend,
                   float blendTime, float weight);

// The model's skeleton (its target at 0x8).
struct Skeleton_000D0A80 {
    char unknown_00[8];
    void *target;
};

// The holder of the model at 0x58.
struct Holder_000D0A80 {
    Skeleton_000D0A80 *skeleton;
};

struct Owner_000D0680 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000D0680 {
    char unknown_000[0x4];
    Owner_000D0680 *owner;
    char unknown_008[0x50];
    Holder_000D0A80 *holder;
    char unknown_05c[0x10];
    Motion_0005F060 *motion_6c;
    Motion_0005F060 *blend_70;
    Motion_0005F060 *blend_74;
    Motion_0005F060 *motion_78;
    Motion_0005F060 *motion_7c;
    float time_80;
    float time_84;
    float time_88;
    float weight;
    char unknown_090[4];
    int mode;
    int previous;
    int phase;
    int blending;

    void func_000D0A80();
};

// The handlers by mode (0x94).
extern void (Object_000D0680::*data_00216730[])();

// Unless the owner has a flag of 0x120: when the mode at 0x94 changes, clears the motion state (the phase at 0x9c,
// the times at 0x80 and 0x84, the blends at 0x70 and 0x74, the weight at 0x8c) with blending (0xa0) on; runs the
// mode's handler from 0x216730; then poses the model at 0x58 with the motion at 0x7c (0x78 without blending) blended
// into the one at 0x6c (time 0x80), through the one at 0x70 when set (func_0005EC20), blends in the one at 0x74 when
// set, and when blending, the one at 0x78 into 0x7c by a quarter.
void Object_000D0680::func_000D0A80()
{
    if (owner->flags & 0x120) {
        return;
    }
    if (mode != previous) {
        phase = 0;
        previous = mode;
        time_84 = 0;
        time_80 = 0;
        blend_70 = 0;
        blend_74 = 0;
        blending = 1;
        weight = 0;
    }
    (this->*data_00216730[mode])();
    Motion_0005F060 *motion;
    if (blending) {
        motion = motion_7c;
    } else {
        motion = motion_78;
    }
    if (blend_70) {
        func_0005EC20(holder->skeleton->target, (int)motion, 0, (int)motion_6c, *(int *)&time_80, blend_70, time_84,
                      weight);
    } else {
        func_0005E7B0(holder->skeleton->target, (int)motion, 0, (int)motion_6c, *(int *)&time_80);
    }
    if (blend_74) {
        func_0005EAF0(holder->skeleton->target, motion, 0.0f, motion, 0.0f, blend_74, time_88);
    }
    if (blending) {
        func_0005EC20(holder->skeleton->target, (int)motion_78, 0, (int)motion_78, 0, motion_7c, 0.0f, 0.25f);
    }
}
