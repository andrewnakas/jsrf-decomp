struct Motion_0005F060;

int func_0005E7B0(void *target, int first, int second, int third, int fourth);

// A posed part: its pose target at 0x8.
struct Part_0009D7E0 {
    char unknown_00[8];
    void *target;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x9a0];
    int motion_9a0;
    char unknown_9a4[0x40];
    int value_9e4;
    char unknown_9e8[0x46c];
    int value_e54;
    char unknown_e58[0x18];
    int value_e70;
    char unknown_e74[0xac];
    Part_0009D7E0 *part;

    Motion_0005F060 *func_000A0150(int index, int plain);
    void func_0009D7E0();
};

// Poses the part at 0xf20 with the motion at 0x9a0 and motion 0x4d (0x12 while 0xe70 is clear) of
// func_000A0150, keeps that index at 0x9e4 and clears 0xe54.
void Object_000A1C50::func_0009D7E0()
{
    if (value_e70) {
        func_0005E7B0(part->target, motion_9a0, 0, (int)func_000A0150(0x4d, 0), 0);
        value_9e4 = 0x4d;
        value_e54 = 0;
    } else {
        func_0005E7B0(part->target, motion_9a0, 0, (int)func_000A0150(0x12, 0), 0);
        value_9e4 = 0x12;
        value_e54 = 0;
    }
}
