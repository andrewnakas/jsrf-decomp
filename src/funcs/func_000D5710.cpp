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

    void func_000D5710();
};

// A handler of the table at 0x216DC8: in mode 0 (0x88) starts motion 24 (kind 0x12 at 0x80) or 34 at time 0, in
// other modes the second motion at 0xf0c (25 or 35) instead, which starts at time 0 either way (phase 1). Then in
// mode 0 plays the motion at half speed, looping, and in other modes plays it once and the second one looping;
// phase 2 when the looping one wraps.
void Object_000D27F0::func_000D5710()
{
    if (phase == 0) {
        if (kind == 0x12) {
            if (mode) {
                upper = set->motions[25];
            } else {
                motion = set->motions[24];
                time = 0.0f;
            }
        } else {
            if (mode) {
                upper = set->motions[35];
            } else {
                motion = set->motions[34];
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
        phase = 2;
    }
}
