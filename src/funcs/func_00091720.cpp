int func_0004A820(int current, int target, int step);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x11c];
    int value_11c;
    char unknown_120[0xc];
    float value_12c;
    char unknown_130[0x8a8];
    int value_9d8;
    char unknown_9dc[0x268];
    int value_c44;
    char unknown_c48[0x14];
    int value_c5c;
    char unknown_c60[0x60];
    int angle_cc0;
    char unknown_cc4[0x10];
    float value_cd4;
    char unknown_cd8[0x23c];
    int value_f14;
    char unknown_f18[0x210];
    int value_1128;
    char unknown_112c[0x48];
    int value_1174;

    void func_0009C550(int value);
    int func_000836A0();
    void func_000A0610(int value);
    void func_000A0DA0();
    void func_00091720();
};

// As func_00091640, but when func_000836A0 refuses clears the speed at 0xcd4 and the rate at 0x12c.
void Object_000A1C50::func_00091720()
{
    if (value_c5c) {
        if (!value_1174) {
            func_000A0610(1);
        }
        return;
    }
    if (value_9d8) {
        if (value_c44 && !value_f14) {
            func_0009C550(0x16);
            return;
        }
        if (!value_1174) {
            func_000A0610(1);
            return;
        }
        value_c5c = 1;
        value_11c = 1;
        return;
    }
    if (func_000836A0()) {
        if (value_cd4 >= 0.0f) {
            angle_cc0 = func_0004A820(angle_cc0, value_1128, 0x38e);
        } else {
            angle_cc0 = func_0004A820(angle_cc0, value_1128 + 0x8000, 0x38e);
        }
        return;
    }
    value_cd4 = 0.0f;
    value_12c = 0.0f;
}
