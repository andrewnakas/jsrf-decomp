struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
int func_0005E7B0(void *target, int first, int second, int third, int fourth);
void func_0005EF30(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);
float func_0014C7F0(float value);

struct Object_000C1440 {
    int func_000C1440(int from, int to);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1440.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves: angles at 0x50, a speed at 0x5c and flags at 0xa4.
struct Desc_000D6350 {
    char unknown_00[0x50];
    int angle_x;
    int angle_y;
    int angle_z;
    float speed;
    char unknown_60[0x44];
    unsigned int flags;
};

// The base of the behaviours the factories of the table at 0x215D68 build.
struct Object_000CD1E0 {
    virtual void func_000D77D0() = 0;

    Desc_000D6350 *desc;
};

// A posed part: its pose target at 0x8.
struct Part_000D79E0 {
    char unknown_00[8];
    void *target;
};

// The limits at 0x30: the widest turn at 0x1c.
struct Limits_000D79E0 {
    char unknown_00[0x1c];
    int turn;
};

// The behaviour func_000D6350 builds.
struct Object_000D6350 : Object_000CD1E0 {
    virtual void func_000D77D0();
    void func_000D79E0();

    int mode;
    char unknown_00c[0x24];
    Limits_000D79E0 *limits;
    char unknown_034[0x94];
    int angle;
    char unknown_0cc[0x18];
    float speed;
    char unknown_0e8[4];
    Part_000D79E0 **parts;
    Motion_0005F060 **motions;
    Motion_0005F060 *motion;
    float time;
    float lean;
    float bank;
};

// Runs `motion` at `time` by `speed`.
static __forceinline void play(Motion_0005F060 *motion, float *time, float speed)
{
    func_0005E030(motion, time, speed, 0);
}

// Moves `value` a sixth toward `target` (snapped to 1 within 0.1 of it), kept within 0..2.
static __forceinline void approach(float *value, float target)
{
    if (func_0014C7F0(target - 1.0f) < 0.1f) {
        target = 1.0f;
    }
    if (*value < target) {
        *value += 0.16666667f;
        if (*value > 2.0f) {
            *value = 2.0f;
        }
    } else if (*value > target) {
        *value -= 0.16666667f;
        if (*value < 0.0f) {
            *value = 0.0f;
        }
    }
}

// Unless the served object has flag 0x100: runs motion 0 at the time at 0xf8 by 0.16 of its speed and poses the part
// with it; in mode 4 leans (0xfc) toward the speed change since 0xe4 (within 1/9, times 9, about 1) and blends in
// motion 1 by it, in other modes keeps the lean at 1; banks (0x100) toward the turn func_000C1440 finds since the
// angle at 0xc8 (within the limit at 0x30's half, over it, about 1) and blends in motions 2 (by the bank) and 3 (by
// the turn). Like func_000E93C0 without its last motion.
void Object_000D6350::func_000D79E0()
{
    if (desc->flags & 0x100) {
        return;
    }
    play(motions[0], &time, desc->speed * 0.16f);
    func_0005E7B0(parts[0]->target, (int)motion, 0, (int)motions[0], *(int *)&time);
    if (mode == 4) {
        float change = desc->speed - speed;
        if (change != 0.0f || lean != 1.0f) {
            if (change > 0.11111111f) {
                change = 0.11111111f;
            } else if (change < -0.11111111f) {
                change = -0.11111111f;
            }
            approach(&lean, change * 9.0f + 1.0f);
            func_0005EF30(parts[0]->target, motion, 0.0f, motion, 0.0f, motions[1], lean);
        }
    } else {
        lean = 1.0f;
    }
    int turn = data_00257CE8->func_000C1440(desc->angle_y, angle);
    if (turn != 0 || bank != 1.0f) {
        int half = limits->turn >> 1;
        if (turn > half) {
            turn = half;
        } else if (turn < -half) {
            turn = -half;
        }
        float share = (float)turn / half + 1.0f;
        approach(&bank, share);
        func_0005EF30(parts[0]->target, motion, 0.0f, motion, 0.0f, motions[2], bank);
        func_0005EF30(parts[0]->target, motion, 0.0f, motion, 0.0f, motions[3], share);
    }
}
