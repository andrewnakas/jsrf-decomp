struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000DCBC0 {
    Motion_0005F060 *motions[64];
};

struct Object_000C1440 {
    int func_000C1440(int from, int to);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1440.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;

struct Owner_000DCBC0 {
    char unknown_00[0x54];
    int angle;
    char unknown_58[0x4];
    float speed;
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Owner_000DCBC0 *owner;
    char unknown_008[0x114];
    int angle;
    char unknown_120[0x70];
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
    void func_000E01C0();
};

// A handler of the table at 0x217A20: first takes motion 16 as the upper motion at 0x19c from time -1 (phase 1).
// While the owner moves (speed at 0x5c), runs motion 32 blended with motion 12 from the time at 0x1cc
// (func_000E0000); standing, plays motion 19 (or 32 when func_000C1440 of the owner's angle and the one at 0x11c is
// 0xb6 or more) once at half speed without a blend. Then plays the upper motion at half speed, looping.
void Object_000DCBC0::func_000E01C0()
{
    if (phase == 0) {
        upper = set->motions[16];
        upper_time = -1.0f;
        phase = 1;
    }
    if (owner->speed != 0.0f) {
        motion = set->motions[32];
        blend = set->motions[12];
        time = time_1b0 = time_1cc;
        func_000E0000();
    } else {
        if (data_00257CE8->func_000C1440(owner->angle, angle) < 0xb6) {
            motion = set->motions[19];
        } else {
            motion = set->motions[32];
        }
        blend = 0;
        func_0005E030(motion, &time, 0.5f, 0);
    }
    func_0005E030(upper, &upper_time, 0.5f, 1);
}
