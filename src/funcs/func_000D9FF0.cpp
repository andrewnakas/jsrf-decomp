struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000D8A40 {
    Motion_0005F060 *motions[32];
};

struct Object_000D8A40 {
    char unknown_000[0xb0];
    Set_000D8A40 *set;
    Motion_0005F060 *motion;
    char unknown_0b8[0x14];
    float time;
    char unknown_0d0[0x10];
    int next;
    char unknown_0e4[0x4];
    int phase;

    void func_000D9FF0();
};

// A handler of the table at 0x2173C0: starts motion 19 at time 0 (phase 1), then plays it at half speed once;
// 6 at 0xe0 when it ends.
void Object_000D8A40::func_000D9FF0()
{
    if (phase == 0) {
        motion = set->motions[19];
        time = 0.0f;
        phase = 1;
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        next = 6;
    }
}
