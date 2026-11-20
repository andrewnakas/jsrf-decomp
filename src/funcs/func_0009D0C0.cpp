struct Motion_0005F060;

int func_0005E7B0(void *target, int first, int second, int third, int fourth);
void func_0005EC20(void *target, int first, int second, int third, int fourth, Motion_0005F060 *blend,
                   float blendFrame, float weight);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

// A posed part: its pose target at 0x8.
struct Part_0009D7E0 {
    char unknown_00[8];
    void *target;
};

// One of the move pairs at data_002104A0: a speed at 0x4 and a motion index at 0xc.
struct Entry_002104A0 {
    int unknown_00;
    float speed;
    int unknown_08;
    int motion;
    char unknown_10[0x20];
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x9a0];
    int motion_9a0;
    char unknown_9a4[0x30];
    float blend;
    char unknown_9d8[0xc];
    int value_9e4;
    char unknown_9e8[0x46c];
    int value_e54;
    char unknown_e58[0x14];
    int move;
    int value_e70;
    char unknown_e74[0xc];
    float time;
    char unknown_e84[0x9c];
    Part_0009D7E0 *part;
    char unknown_f24[0x1fc];
    int turn;

    Entry_002104A0 *func_000A0120(int index);
    Motion_0005F060 *func_000A0150(int index, int plain);
    void func_0009D0C0();
};

// With 0xe70 set runs and poses motion 0x4c (func_0005E030 at the move's speed, func_0005E7B0). Otherwise eases the
// blend at 0x9d4 by 0.06 toward the turn at 0x1120 (its size over 0x18e3, at most 1; set when within 0.06), runs
// motion 0xe and poses it blended with motion 0xf by that much (func_0005EC20). Keeps the motion at 0x9e4 and clears
// 0xe54.
void Object_000A1C50::func_0009D0C0()
{
    if (value_e70) {
        func_0005E030(func_000A0150(0x4c, 0), &time, func_000A0120(move)->speed, 0);
        func_0005E7B0(part->target, motion_9a0, 0, (int)func_000A0150(0x4c, 0), *(int *)&time);
        value_9e4 = 0x4c;
        value_e54 = 0;
        return;
    }
    int size = turn < 0 ? -turn : turn;
    float target;
    if (size < 0x18e3) {
        target = size * 0.00015696124f;
    } else {
        target = 1.0f;
    }
    if (target > blend) {
        blend += 0.06f;
    }
    if (target < blend) {
        blend -= 0.06f;
    }
    float difference = blend - target;
    if ((difference < 0.0f ? -difference : difference) <= 0.06) {
        blend = target;
    }
    func_0005E030(func_000A0150(0xe, 0), &time, func_000A0120(move)->speed, 0);
    func_0005EC20(part->target, motion_9a0, 0, (int)func_000A0150(0xe, 0), *(int *)&time, func_000A0150(0xf, 0), time,
                  blend);
    value_9e4 = 0xe;
    value_e54 = 0;
}
