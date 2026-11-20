struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000D27F0 {
    Motion_0005F060 *motions[64];
};

struct Object_000D27F0 {
    char unknown_000[0x80];
    int kind;
    char unknown_084[0x4];
    int mode;
    char unknown_08c[0xe74];
    Set_000D27F0 *set;
    Motion_0005F060 *motion;
    char unknown_f08[0x4];
    Motion_0005F060 *upper;
    char unknown_f10[0xc];
    float time;
    char unknown_f20[0x4];
    float upper_time;
    char unknown_f28[0x10];
    int phase;

    void func_000D58E0();
};

// A handler of the table at 0x216DC8: in mode 0 (0x88) starts motion 28 (kind 0x12 at 0x80) or 38 at time 0, in
// other modes the second motion at 0xf0c (29 or 39) instead, which starts at time 0 either way (phase 1). Then in
// other modes plays the motion once and the second one looping, phase 2 when it wraps; in mode 0 plays the motion
// looping and, when it wraps, starts motion 44 at time 0 (phase 2).
void Object_000D27F0::func_000D58E0()
{
    if (phase == 0) {
        if (kind == 0x12) {
            if (mode) {
                upper = set->motions[29];
            } else {
                motion = set->motions[28];
                time = 0.0f;
            }
        } else {
            if (mode) {
                upper = set->motions[39];
            } else {
                motion = set->motions[38];
                time = 0.0f;
            }
        }
        upper_time = 0.0f;
        phase = 1;
        return;
    }
    if (mode) {
        func_0005E030(motion, &time, 0.5f, 0);
        if (func_0005E030(upper, &upper_time, 0.5f, 1)) {
            phase = 2;
        }
    } else if (func_0005E030(motion, &time, 0.5f, 1)) {
        motion = set->motions[44];
        time = 0.0f;
        phase = 2;
    }
}
