struct Motion_0005F060;

int func_0005E7B0(void *target, int first, int second, int third, int fourth);
void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);
void func_0005EC20(void *target, int first, int second, int third, int fourth, Motion_0005F060 *blend,
                   float blendTime, float weight);

struct Object_000C5B50;

// The model's skeleton (its target at 0x8).
struct Skeleton_000D97D0 {
    char unknown_00[8];
    void *target;
};

// The model at 0xa4.
struct Model_000D97D0 {
    Skeleton_000D97D0 *skeleton;
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE63C (handlers by state at 0x217378).
struct Object_000D8A40 : Object_000CC600 {
    virtual void func_000CD1E0();

    void func_000D97D0();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[8];
    char unknown_014[0x90];
    Model_000D97D0 *model;
    char unknown_0a8[0xc];
    Motion_0005F060 *motion_b4;
    Motion_0005F060 *blend_b8;
    Motion_0005F060 *blend_bc;
    Motion_0005F060 *motion_c0;
    Motion_0005F060 *motion_c4;
    char unknown_0c8[4];
    float time_cc;
    float time_d0;
    float time_d4;
    float weight;
    char unknown_0dc[4];
    int mode;
    int previous;
    int value_e8;
    Motion_0005F060 *blend_ec;
    float time_f0;
};

extern void (Object_000D8A40::*data_002173C0[])();

// When the mode at 0xe0 changes, clears the motion state (0xe8, the times at 0xcc and 0xd0, the blends at 0xb8, 0xbc
// and 0xec, the time at 0xf0); runs the mode's handler from 0x2173C0; then poses the model with the motion at 0xc4
// blended into the one at 0xb4 (time 0xcc), through the one at 0xb8 when set (func_0005EC20), blends in those at
// 0xbc and 0xec when set, and finally the one at 0xc0 into 0xc4 by a quarter.
void Object_000D8A40::func_000D97D0()
{
    if (mode != previous) {
        value_e8 = 0;
        previous = mode;
        time_d0 = 0;
        time_cc = 0;
        blend_b8 = 0;
        blend_bc = 0;
        blend_ec = 0;
        time_f0 = 0;
    }
    (this->*data_002173C0[mode])();
    if (blend_b8) {
        func_0005EC20(model->skeleton->target, (int)motion_c4, 0, (int)motion_b4, *(int *)&time_cc, blend_b8, time_d0,
                      weight);
    } else {
        func_0005E7B0(model->skeleton->target, (int)motion_c4, 0, (int)motion_b4, *(int *)&time_cc);
    }
    if (blend_bc) {
        func_0005EAF0(model->skeleton->target, motion_c4, 0.0f, motion_c4, 0.0f, blend_bc, time_d4);
    }
    if (blend_ec) {
        func_0005EAF0(model->skeleton->target, motion_c4, 0.0f, motion_c4, 0.0f, blend_ec, time_f0);
    }
    func_0005EC20(model->skeleton->target, (int)motion_c0, 0, (int)motion_c0, 0, motion_c4, 0.0f, 0.25f);
}
