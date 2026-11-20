struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000ECB50 {
    Motion_0005F060 *motions[32];
};

// The object func_000ECB50 builds (Node and a chain link at 0x44); this is a handler of the table at 0x258520 its
// slot 1 (func_000ECDB0) runs, filled in by the dynamic initializer func_0018C0C0.
struct Object_000ECB50 {
    char unknown_000[0x90];
    unsigned int flags;
    char unknown_094[0x94];
    int next;
    char unknown_12c[8];
    int index;
    int value_138;
    char unknown_13c[8];
    Set_000ECB50 *set;
    Motion_0005F060 *motion;
    Motion_0005F060 *motion_b;
    char unknown_150[4];
    float time;
    float time_b;

    void func_000EC350();
};

// Entry 1 of the handlers at 0x258520: drops the flag 0x2000000 and plays the motion at 0x148 at half speed, looping;
// when it wraps, state 2, the index at 0x134 steps through 0-3, and the motions restart at time 0: motion 12 + index
// and motion 2 of the set at 0x144; 0x138 is cleared.
void Object_000ECB50::func_000EC350()
{
    flags &= ~0x2000000;
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        next = 2;
        if (index != 3) {
            index++;
        } else {
            index = 0;
        }
        motion = set->motions[12 + index];
        time = 0.0f;
        motion_b = set->motions[2];
        time_b = 0.0f;
        value_138 = 0;
    }
}
