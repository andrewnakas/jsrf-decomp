struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000E7F50 {
    Motion_0005F060 *motions[32];
};

struct Holder_000E7F50 {
    char unknown_00[8];
    void *target;
};

// The object func_000E7F50 builds; these are the handlers by state its func_000ED010 runs (the member pointers at
// 0x258560, filled in by the dynamic initializer func_0018C150).
struct Object_000E7F50 {
    char unknown_000[0x114];
    Holder_000E7F50 *holder;
    Set_000E7F50 *set;
    Motion_0005F060 *motion;
    Motion_0005F060 *motion_b;
    char unknown_124[4];
    int value_128;
    float time;
    float time_b;
    char unknown_134[0xc];
    float timer;
    int next;
    char unknown_148[4];
    int phase;

    void func_000ED2A0();
};

// Entry 3 of the handlers at 0x258560: starts motion 17 of the set at 0x118 at time 0 (phase 1); then plays it at
// half speed once, the result unused.
void Object_000E7F50::func_000ED2A0()
{
    if (phase == 0) {
        motion = set->motions[17];
        time = 0.0f;
        phase = 1;
        return;
    }
    func_0005E030(motion, &time, 0.5f, 0);
}
