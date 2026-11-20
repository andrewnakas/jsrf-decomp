struct Motion_0005F060;

int func_0004A7F0(int first, int second);
int func_0005E7B0(void *target, int first, int second, int third, int fourth);
void func_0005EC20(void *target, int first, int second, int third, int fourth, Motion_0005F060 *blend,
                   float blendFrame, float weight);
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
    char unknown_9e8[0x2d8];
    int value_cc0;
    char unknown_cc4[0x10];
    float value_cd4;
    char unknown_cd8[0x17c];
    int value_e54;
    char unknown_e58[0x28];
    float time;
    char unknown_e84[0x9c];
    Part_0009D7E0 *part;
    char unknown_f24[0x204];
    int value_1128;

    Motion_0005F060 *func_000A0150(int index, int plain);
    void func_0009D990();
};

// Poses the part at 0xf20 by how far 0xcc0 is from 0x1128 (func_0004A7F0, either way): below 0x4000 with motion 0,
// from 0x6aaa with motion 0x78, between them blending the two (func_0005EC20) by the share of the way; keeps 0 or 0x78
// (from 0x5555) at 0x9e4. Then runs motion 0 on the time at 0xe80 at 2.16 times the speed at 0xcd4 (at least 0.5) and
// clears 0xe54.
void Object_000A1C50::func_0009D990()
{
    int angle = func_0004A7F0(value_cc0, value_1128) < 0 ? -func_0004A7F0(value_cc0, value_1128)
                                                          : func_0004A7F0(value_cc0, value_1128);
    float speed;
    if (value_cd4 < 0.23148148f) {
        speed = 0.5f;
    } else {
        speed = value_cd4 * 2.16f;
    }
    if (angle < 0x4000) {
        func_0005E7B0(part->target, motion_9a0, 0, (int)func_000A0150(0, 0), *(int *)&time);
        value_9e4 = 0;
    } else if (angle < 0x6aaa) {
        func_0005EC20(part->target, motion_9a0, 0, (int)func_000A0150(0, 0), *(int *)&time, func_000A0150(0x78, 0),
                      time, (angle - 0x4000) * 9.155832e-05f);
        value_9e4 = angle < 0x5555 ? 0 : 0x78;
    } else {
        func_0005E7B0(part->target, motion_9a0, 0, (int)func_000A0150(0x78, 0), *(int *)&time);
        value_9e4 = 0x78;
    }
    func_0005E030(func_000A0150(0, 0), &time, speed, 0);
    value_e54 = 0;
}
