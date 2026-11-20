struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000D0680 {
    Motion_0005F060 *motions[32];
};

struct Object_000D0680 {
    char unknown_000[0x58];
    Set_000D0680 *set_b;
    Motion_0005F060 *motion_b;
    char unknown_060[0x8];
    Set_000D0680 *set;
    Motion_0005F060 *motion;
    char unknown_070[0x10];
    float time;
    char unknown_084[0x10];
    int next;
    char unknown_098[0x4];
    int phase;

    void func_000D1020();
};

// A handler of the table at 0x216730: starts motion 10 of the set at 0x68 at time 0, with motion 4 of the set at
// 0x58 at 0x5c (phase 1); then plays the first at half speed, looping; phase 2 when it wraps.
void Object_000D0680::func_000D1020()
{
    if (phase == 0) {
        motion = set->motions[10];
        motion_b = set_b->motions[4];
        time = 0.0f;
        phase = 1;
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        phase = 2;
    }
}
