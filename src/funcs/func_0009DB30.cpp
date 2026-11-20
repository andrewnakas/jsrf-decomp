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
    char unknown_9a4[0x40];
    int value_9e4;
    char unknown_9e8[0x2ec];
    float speed;
    char unknown_cd8[0x17c];
    int value_e54;
    char unknown_e58[0x28];
    float time;
    char unknown_e84[0x9c];
    Part_0009D7E0 *part;

    Motion_0005F060 *func_000A0150(int index, int plain);
    void func_0009DB30();
};

// Poses the part at 0xf20 with motion 0x79 (func_000A0150) at the time at 0xe80 and runs it on (func_0005E030) at
// half speed while the speed at 0xcd4 is below 0.2315, at 2.16 times that speed above; 0x79 at 0x9e4, 0xe54 cleared.
void Object_000A1C50::func_0009DB30()
{
    float step;
    if (speed < 0.23148148f) {
        step = 0.5f;
    } else {
        step = speed * 2.16f;
    }
    func_0005E7B0(part->target, motion_9a0, 0, (int)func_000A0150(0x79, 0), *(int *)&time);
    func_0005E030(func_000A0150(0x79, 0), &time, step, 0);
    value_9e4 = 0x79;
    value_e54 = 0;
}
