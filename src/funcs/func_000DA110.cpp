struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000D8A40 {
    Motion_0005F060 *motions[32];
};

// For each of the first 23 motions of a set, the motion that follows it (by index).
extern int data_002173F8[23];

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

    void func_000DA110();
};

// A handler of the table at 0x2173C0: finds the current motion among the set's first 23 and starts the one
// data_002173F8 names for it at time 0 (phase 1), then plays it at half speed, looping; 12 at 0xe0 when it wraps.
void Object_000D8A40::func_000DA110()
{
    if (phase == 0) {
        Set_000D8A40 *motions = set;
        Motion_0005F060 *current = motion;
        Motion_0005F060 **entry;
        unsigned int i;
        for (i = 0, entry = motions->motions; i < 23; i++, entry++) {
            if (current == *entry) {
                motion = motions->motions[data_002173F8[i]];
                break;
            }
        }
        time = 0.0f;
        phase = 1;
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        next = 12;
    }
}
