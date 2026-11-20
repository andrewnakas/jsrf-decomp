// The object at 0x2a0 of the player: speed limits and their divisors.
struct Object_00094780 {
    char unknown_00[0x24];
    float divisor_24;
    float limit_28;
    float divisor_2c;
    float limit_30;
    float divisor_34;
    float limit_38;
    float divisor_3c;
    float divisor_40;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x11c];
    int value_11c;
    int value_120;
    int value_124;
    int value_128;
    float value_12c;
    char unknown_130[0x170];
    Object_00094780 *object_2a0;
    char unknown_2a4[0xa30];
    float value_cd4;

    void func_000A0E20();
    void func_000A22F0();
};

// Value 1 at 0x120 with 0x124 and 0x128 cleared; the speed at 0xcd4 picks the state at 0x11c (0x12 when not over 0,
// 0xf, 0xe under the limits at 0x38 and 0x30 of the object at 0x2a0, else 0x10 and func_000A22F0) and its rate at 0x12c,
// the speed over the matching divisor, negated.
void Object_000A1C50::func_000A0E20()
{
    value_128 = 0;
    value_124 = 0;
    value_120 = 1;
    if (value_cd4 <= 0.0f) {
        value_12c = -(value_cd4 / object_2a0->divisor_40);
        value_11c = 0x12;
    } else if (value_cd4 < object_2a0->limit_38) {
        value_12c = -(value_cd4 / object_2a0->divisor_3c);
        value_11c = 0xf;
    } else if (value_cd4 < object_2a0->limit_30) {
        value_12c = -(value_cd4 / object_2a0->divisor_34);
        value_11c = 0xe;
    } else {
        float rate;
        if (value_cd4 < object_2a0->limit_28) {
            rate = value_cd4 / object_2a0->divisor_2c;
        } else {
            rate = value_cd4 / object_2a0->divisor_24;
        }
        value_12c = -rate;
        value_11c = 0x10;
        func_000A22F0();
    }
}
