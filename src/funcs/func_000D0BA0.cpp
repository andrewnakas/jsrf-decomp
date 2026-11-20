struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000D0680 {
    Motion_0005F060 *motions[32];
};

struct Owner_000D0680 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000D0680 {
    char unknown_000[0x4];
    Owner_000D0680 *owner;
    char unknown_008[0x50];
    Set_000D0680 *set_b;
    Motion_0005F060 *motion_b;
    char unknown_060[0x8];
    Set_000D0680 *set;
    Motion_0005F060 *motion;
    char unknown_070[0x10];
    float time;
    char unknown_084[0x10];
    int next;
    char unknown_098[0x4];
    int phase;

    void func_000D0BA0();
};

// A handler of the table at 0x216730 (entry 0): starts motion 1 of the set at 0x68 with motion 5 of the set at 0x58
// (the owner has flag 0x2000000), else motions 0 and 4, at time 0 (phase 1); then plays the first at half speed once,
// the result unused.
void Object_000D0680::func_000D0BA0()
{
    if (phase == 0) {
        if (owner->flags & 0x2000000) {
            motion = set->motions[1];
            motion_b = set_b->motions[5];
        } else {
            motion = set->motions[0];
            motion_b = set_b->motions[4];
        }
        time = 0.0f;
        phase = 1;
        return;
    }
    func_0005E030(motion, &time, 0.5f, 0);
}
