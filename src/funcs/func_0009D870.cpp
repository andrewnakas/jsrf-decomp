struct Motion_0005F060;

void func_0005E7B0(void *target, int first, int second, int third, int fourth);

// A posed part: its pose target at 0x8.
struct Part_0009D870 {
    char unknown_00[8];
    void *target;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x9a0];
    int motion_9a0;
    char unknown_9a4[0x40];
    int value_9e4;
    char unknown_9e8[0x1a8];
    float ratio;
    char unknown_b94[0x2c0];
    int value_e54;
    char unknown_e58[0x18];
    int value_e70;
    char unknown_e74[0xac];
    Part_0009D870 *part;
    char unknown_f24[0x1fc];
    int value_1120;

    Motion_0005F060 *func_000A0150(int index, int plain);
    void func_0009D870();
};

// Poses the part at 0xf20 with the motion at 0x9a0, the ratio at 0xb90 and motion 0x70 / 0x6f (0x41 / 0x40 while
// 0xe70 is clear) of func_000A0150, the first when the value at 0x1120 is negative; keeps that index at 0x9e4 and
// clears 0xe54.
void Object_000A1C50::func_0009D870()
{
    if (value_e70) {
        if (value_1120 < 0) {
            func_0005E7B0(part->target, motion_9a0, 0, (int)func_000A0150(0x70, 0), *(int *)&ratio);
            value_e54 = 0;
            value_9e4 = 0x70;
        } else {
            func_0005E7B0(part->target, motion_9a0, 0, (int)func_000A0150(0x6f, 0), *(int *)&ratio);
            value_e54 = 0;
            value_9e4 = 0x6f;
        }
    } else {
        if (value_1120 < 0) {
            func_0005E7B0(part->target, motion_9a0, 0, (int)func_000A0150(0x41, 0), *(int *)&ratio);
            value_e54 = 0;
            value_9e4 = 0x41;
        } else {
            func_0005E7B0(part->target, motion_9a0, 0, (int)func_000A0150(0x40, 0), *(int *)&ratio);
            value_e54 = 0;
            value_9e4 = 0x40;
        }
    }
}
