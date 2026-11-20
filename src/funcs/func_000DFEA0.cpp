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

    void func_000DFEA0();
};

// A handler of the table at 0x217AB8: starts motion 10 at time 0 (phase 1), then loops it at half speed; in phase 2,
// 25 at 0x1c0 first.
void Object_000DCBC0::func_000DFEA0()
{
    if (phase == 0) {
        motion = set->motions[10];
        time = 0.0f;
        phase = 1;
        return;
    }
    if (phase == 2) {
        next = 0x19;
    }
    func_0005E030(motion, &time, 0.5f, 0);
}
