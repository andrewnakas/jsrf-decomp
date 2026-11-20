struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000D8A40 {
    Motion_0005F060 *motions[32];
};

struct Object_000D8A40 {
    char unknown_000[0x54];
    int lean;
    char unknown_058[0x58];
    Set_000D8A40 *set;
    Motion_0005F060 *motion;
    char unknown_0b8[0x14];
    float time;
    char unknown_0d0[0x18];
    int phase;
    Motion_0005F060 *lean_motion;
    float lean_weight;
    float turn_time;

    void func_000D9A10();
    void func_000D9CD0();
};

// A handler of the table at 0x2173C0: starts motion 7 at time 0 (phase 1) with the lean motion at 0xec (10 for a
// negative lean at 0x54, 13 for a positive one) weighted by the lean (1/8192 or 1/16384 per unit, at most 1); then
// plays it at half speed, looping, moves to phase 2 when it wraps, and turns (func_000D9A10).
void Object_000D8A40::func_000D9CD0()
{
    if (phase == 0) {
        motion = set->motions[7];
        time = 0.0f;
        turn_time = 0.0f;
        phase = 1;
        int amount = lean;
        if (amount < 0) {
            lean_motion = set->motions[10];
            lean_weight = (float)-amount * (1.0f / 8192.0f);
            if (lean_weight > 1.0f) {
                lean_weight = 1.0f;
            }
        } else if (amount > 0) {
            lean_motion = set->motions[13];
            lean_weight = (float)amount * (1.0f / 16384.0f);
            if (lean_weight > 1.0f) {
                lean_weight = 1.0f;
            }
        }
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        phase = 2;
    }
    func_000D9A10();
}
