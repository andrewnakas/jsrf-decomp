struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

int func_0005E7B0(void *target, int first, int second, int third, int fourth);

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

    void func_000ED3C0();
};

// Entry 6 of the handlers at 0x258560: once (phase 0 to 1), takes motion 5 of the set at 0x118 at time 49 and hands it
// to func_0005E7B0 with the holder's target and 0x128 (the time goes as the bits of 49.0f).
void Object_000E7F50::func_000ED3C0()
{
    if (phase == 0) {
        motion = set->motions[5];
        time = 49.0f;
        func_0005E7B0(holder->target, value_128, 0, (int)motion, 0x42440000);
        phase++;
    }
}
