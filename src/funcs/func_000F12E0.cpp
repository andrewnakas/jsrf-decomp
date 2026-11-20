struct Motion_0005F060;

void func_0005E7B0(void *target, int first, int second, int third, int fourth);
void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);
void func_0005EF30(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);

// A posed part (0x78 and 0x7c): its pose target at 0x8.
struct Part_000F12E0 {
    char unknown_00[8];
    void *target;
};

// The class whose table is at 0x1CF02C (constructor func_000F1820; slot 0 func_000F1C30 calls this).
struct Object_000F1820 {
    char unknown_000[0x78];
    Part_000F12E0 *first;
    Part_000F12E0 *second;
    char unknown_080[4];
    int *keys;
    Motion_0005F060 *blends[8];
    Motion_0005F060 *motion;
    Motion_0005F060 *secondMotion;
    int value_b0;
    float times[8];

    void func_000F12E0();
};

// Poses both parts with their motions at 0xa8 and 0xac (func_0005E7B0 with the keys at 0x84 and the value at 0xb0),
// then blends in the motions at 0x88 that are set: 0-5 on the first part (func_0005EAF0), 6 and 7 on the second
// (func_0005EF30), with the times at 0xb4 (6 and 7 share those of 4 and 5).
void Object_000F1820::func_000F12E0()
{
    func_0005E7B0(first->target, (int)motion, 0, keys[0], value_b0);
    func_0005E7B0(second->target, (int)secondMotion, 0, keys[1], value_b0);
    int i;
    for (i = 0; i < 4; i++) {
        if (blends[i]) {
            func_0005EAF0(first->target, motion, 0.0f, motion, 0.0f, blends[i], times[i]);
        }
    }
    for (i = 0; i < 2; i++) {
        if (blends[i + 4]) {
            func_0005EAF0(first->target, motion, 0.0f, motion, 0.0f, blends[i + 4], times[i + 4]);
        }
        if (blends[i + 6]) {
            func_0005EF30(second->target, secondMotion, 0.0f, secondMotion, 0.0f, blends[i + 6], times[i + 4]);
        }
    }
}
