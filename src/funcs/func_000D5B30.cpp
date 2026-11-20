struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000D27F0 {
    Motion_0005F060 *motions[64];
};

struct Object_000D27F0 {
    char unknown_000[0xf00];
    Set_000D27F0 *set;
    Motion_0005F060 *motion;
    char unknown_f08[0x14];
    float time;
    char unknown_f20[0x18];
    int phase;

    void func_000D5B30();
};

// A handler of the table at 0x216DC8: starts motion 47 at time 0 (phase 1), then plays it at half speed once;
// phase 2 when it ends.
void Object_000D27F0::func_000D5B30()
{
    if (phase == 0) {
        motion = set->motions[47];
        time = 0.0f;
        phase = 1;
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        phase = 2;
    }
}
