struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000D27F0 {
    Motion_0005F060 *motions[64];
};

struct Object_000D27F0 {
    char unknown_000[0x80];
    int kind;
    char unknown_084[0x4];
    int mode;
    char unknown_08c[0xe74];
    Set_000D27F0 *set;
    Motion_0005F060 *motion;
    char unknown_f08[0x14];
    float time;
    char unknown_f20[0x10];
    int next;
    char unknown_f34[0x4];
    int phase;

    void func_000D5600();
};

// A handler of the table at 0x216DC8: starts, by the mode at 0x88, motion 3 or 5 (mode 1) or 50 or 52 (mode 2), the
// first for kind 0x12 at 0x80, at time 0 (phase 1); then plays it at half speed, looping; 8 at 0xf30 when it wraps.
// Any other mode reads an index that was never set.
void Object_000D27F0::func_000D5600()
{
    int index;
    if (phase == 0) {
        switch (mode) {
        case 1:
            index = kind == 0x12 ? 3 : 5;
            break;
        case 2:
            index = kind == 0x12 ? 50 : 52;
            break;
        }
        motion = set->motions[index];
        time = 0.0f;
        phase = 1;
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        next = 8;
    }
}
