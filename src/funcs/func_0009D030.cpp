struct Motion_0005F060;

int func_0005E7B0(void *target, int first, int second, int third, int fourth);
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
    char unknown_9a4[0x40];
    int value_9e4;
    char unknown_9e8[0x46c];
    int value_e54;
    char unknown_e58[0x14];
    int move;
    char unknown_e70[0x10];
    float time;
    char unknown_e84[0x9c];
    Part_0009D7E0 *part;

    Entry_002104A0 *func_000A0120(int index);
    Motion_0005F060 *func_000A0150(int index, int plain);
    int func_000A0260(int index);
    void func_0009D030();
};

// Runs the motion of the current move (0xe6c: its motion index at 0xc and speed at 0x4, func_000A0120) on the time at
// 0xe80 (func_0005E030), poses the part at 0xf20 with it at that time (func_0005E7B0), keeps the index at 0x9e4 and
// func_000A0260 of it at 0xe54.
void Object_000A1C50::func_0009D030()
{
    int motion = func_000A0120(move)->motion;
    func_0005E030(func_000A0150(motion, 0), &time, func_000A0120(move)->speed, 0);
    func_0005E7B0(part->target, motion_9a0, 0, (int)func_000A0150(motion, 0), *(int *)&time);
    value_9e4 = motion;
    value_e54 = func_000A0260(motion);
}
