struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Object_000D27F0 {
    char unknown_000[0xf04];
    Motion_0005F060 *motion;
    char unknown_f08[0x14];
    float time;
    char unknown_f20[0x18];
    int phase;

    void func_000D52A0();
    void func_000D5350();
};

// A handler of the table at 0x216DC8: keeps the current motion (phase 1), then plays it at half speed once, the
// result unused, and goes on with func_000D52A0.
void Object_000D27F0::func_000D5350()
{
    if (phase == 0) {
        phase = 1;
        return;
    }
    func_0005E030(motion, &time, 0.5f, 0);
    func_000D52A0();
}
