struct Motion_0005F060;

int func_0005E7B0(void *target, int first, int second, int third, int fourth);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

// A posed part: its pose target at 0x8.
struct Part_0009D7E0 {
    char unknown_00[8];
    void *target;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x9a0];
    int motion_9a0;
    char unknown_9a4[0x34];
    int value_9d8;
    char unknown_9dc[8];
    int value_9e4;
    char unknown_9e8[0x46c];
    int value_e54;
    char unknown_e58[0xc8];
    Part_0009D7E0 *part;
    char unknown_f24[0x1d4];
    Motion_0005F060 *extra;
    float extraTime;

    void func_0009DBD0();
};

// With an extra motion at 0x10f8, poses the part at 0xf20 with it at its time (func_0005E7B0) and runs it on (half
// speed, once, func_0005E030), setting 0x9d8 when it ends; clears 0xe54 and puts -1 at 0x9e4. Without one, sets
// 0x9d8 at once.
void Object_000A1C50::func_0009DBD0()
{
    if (extra) {
        func_0005E7B0(part->target, motion_9a0, 0, (int)extra, *(int *)&extraTime);
        if (!func_0005E030(extra, &extraTime, 0.5f, 1)) {
            value_9e4 = -1;
            value_e54 = 0;
            return;
        }
        value_9e4 = -1;
        value_e54 = 0;
        value_9d8 = 1;
    } else {
        value_9e4 = -1;
        value_e54 = 0;
        value_9d8 = 1;
    }
}
