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

    void func_000D53C0();
};

// A handler of the table at 0x216DC8: in mode 0 (0x88) starts motion 26 (kind 0x12 at 0x80) or 36 at time 0, in
// other modes the second motion at 0xf0c (27 or 37) instead, which starts at time 0 either way (phase 1). Then
// plays the motion, and in other modes the second one too, at half speed once, the results unused.
void Object_000D27F0::func_000D53C0()
{
    if (phase == 0) {
        if (kind == 0x12) {
            if (mode) {
                upper = set->motions[27];
            } else {
                motion = set->motions[26];
                time = 0.0f;
            }
        } else {
            if (mode) {
                upper = set->motions[37];
            } else {
                motion = set->motions[36];
                time = 0.0f;
            }
        }
        upper_time = 0.0f;
        phase = 1;
        return;
    }
    func_0005E030(motion, &time, 0.5f, 0);
    if (mode) {
        func_0005E030(upper, &upper_time, 0.5f, 0);
    }
}
