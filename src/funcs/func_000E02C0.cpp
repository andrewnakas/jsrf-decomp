struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000DCBC0 {
    Motion_0005F060 *motions[64];
};

struct Owner_000DCBC0 {
    char unknown_00[0x5c];
    float speed;
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Owner_000DCBC0 *owner;
    char unknown_008[0x188];
    Set_000DCBC0 *set;
    Motion_0005F060 *motion;
    Motion_0005F060 *blend;
    Motion_0005F060 *upper;
    char unknown_1a0[0xc];
    float time;
    float time_1b0;
    float upper_time;
    char unknown_1b8[0x8];
    int next;
    char unknown_1c4[0x4];
    int phase;
    float time_1cc;

    void func_000E0000();
    void func_000E02C0();
};

// A handler of the table at 0x217A20: first takes motion 18 as the upper motion at 0x19c from time -1 (phase 1).
// While the owner moves (speed at 0x5c), runs motion 32 blended with motion 12 from the time at 0x1cc
// (func_000E0000); standing, plays motion 19 once at half speed without a blend. Then plays the upper motion at half
// speed, looping; 1 at 0x1c0 when it wraps.
void Object_000DCBC0::func_000E02C0()
{
    if (phase == 0) {
        upper = set->motions[18];
        upper_time = -1.0f;
        phase = 1;
    }
    if (owner->speed != 0.0f) {
        motion = set->motions[32];
        blend = set->motions[12];
        time = time_1b0 = time_1cc;
        func_000E0000();
    } else {
        motion = set->motions[19];
        blend = 0;
        func_0005E030(motion, &time, 0.5f, 0);
    }
    if (func_0005E030(upper, &upper_time, 0.5f, 1)) {
        next = 1;
    }
}
