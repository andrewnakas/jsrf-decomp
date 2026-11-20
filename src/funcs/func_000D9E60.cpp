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
    char unknown_0d0[0x18];
    int phase;
    char unknown_0ec[0x8];
    float turn_time;

    void func_000D9A10();
    void func_000D9E60();
};

// A handler of the table at 0x2173C0: starts motion 9 at time 0 with the turn time (0xf4) cleared (phase 1), then
// plays it at half speed, looping, moves to phase 2 when it wraps, and turns (func_000D9A10).
void Object_000D8A40::func_000D9E60()
{
    if (phase == 0) {
        motion = set->motions[9];
        time = 0.0f;
        turn_time = 0.0f;
        phase = 1;
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        phase = 2;
    }
    func_000D9A10();
}
