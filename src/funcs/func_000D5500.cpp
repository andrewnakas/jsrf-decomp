struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000D27F0 {
    Motion_0005F060 *motions[32];
};

struct Object_000D27F0 {
    char unknown_000[0x80];
    int kind;
    char unknown_084[0xe7c];
    Set_000D27F0 *set;
    Motion_0005F060 *motion;
    char unknown_f08[0x14];
    float time;
    char unknown_f20[0x18];
    int phase;

    void func_000D5500();
};

// A handler of the table at 0x216DC8: starts motion 8 (kind 0x12 at 0x80) or 11 (other kinds) at time 0 (phase 1),
// then plays it at half speed, looping; phase 2 when it wraps.
void Object_000D27F0::func_000D5500()
{
    if (phase == 0) {
        if (kind == 0x12) {
            motion = set->motions[8];
        } else {
            motion = set->motions[11];
        }
        time = 0.0f;
        phase = 1;
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        phase = 2;
    }
}
