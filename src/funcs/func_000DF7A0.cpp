struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000DCBC0 {
    Motion_0005F060 *motions[32];
};

struct Object_000DCBC0 {
    char unknown_000[0x190];
    Set_000DCBC0 *set;
    Motion_0005F060 *motion;
    char unknown_198[0x14];
    float time;
    char unknown_1b0[0x10];
    int next;
    char unknown_1c4[4];
    int phase;

    void func_000DF7A0();
};

// A handler of the table at 0x217AB8: starts motion 4 at time 0 (phase 1), then plays it at half speed once;
// 7 at 0x1c0 when it ends.
void Object_000DCBC0::func_000DF7A0()
{
    if (phase == 0) {
        motion = set->motions[4];
        time = 0.0f;
        phase = 1;
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        next = 7;
    }
}
