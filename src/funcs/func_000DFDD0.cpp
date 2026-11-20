struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000DCBC0 {
    Motion_0005F060 *motions[64];
};

// For each of the first 33 motions of a set, the motion that follows it (by index).
extern int data_00217B28[33];

struct Object_000DCBC0 {
    char unknown_000[0x190];
    Set_000DCBC0 *set;
    Motion_0005F060 *motion;
    char unknown_198[0x14];
    float time;
    char unknown_1b0[0x10];
    int next;
    char unknown_1c4[0x4];
    int phase;

    void func_000DFDD0();
};

// A handler of the table at 0x217A20: finds the current motion among the set's first 33 and starts the one
// data_00217B28 names for it at time 0 (phase 1), then plays it at half speed, looping; 23 at 0x1c0 when it wraps.
void Object_000DCBC0::func_000DFDD0()
{
    if (phase == 0) {
        Set_000DCBC0 *motions = set;
        Motion_0005F060 *current = motion;
        Motion_0005F060 **entry;
        unsigned int i;
        for (i = 0, entry = motions->motions; i < 33; i++, entry++) {
            if (current == *entry) {
                motion = motions->motions[data_00217B28[i]];
                break;
            }
        }
        time = 0.0f;
        phase = 1;
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        next = 23;
    }
}
