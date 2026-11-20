struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

// The thirteen motions the handlers of the table at 0x218DD0 play.
struct Set_000E5FF0 {
    Motion_0005F060 *motions[13];
};

struct Object_000E5FF0 {
    char unknown_00[0x34];
    int phase;
    char unknown_38[0x20];
    Set_000E5FF0 *set;
    Motion_0005F060 *motion;
    float time;

    void func_000E59A0();
};

// A handler of the table at 0x218DD0: starts motion 10 at time 0 (phase 1), then plays it at half speed once; phase 2
// when it ends.
void Object_000E5FF0::func_000E59A0()
{
    if (phase == 0) {
        motion = set->motions[10];
        time = 0.0f;
        phase = 1;
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        phase = 2;
    }
}
