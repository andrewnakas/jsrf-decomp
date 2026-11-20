struct Data_00093920 {
    char unknown_00[0x24];
    int value;
    char unknown_28[4];
    int value_2c;
    char unknown_30[8];
    int value_38;
    int value_3c;
};

struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;
    int value_11c;
    char unknown_120[0xb70];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float value_cd4;

    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093BB0();
};

// Halves the value at 0xcd4, 0xa3 at 0x11c and 1 at 0x118, then func_00092FF0(data->value, 1, 1, 1);
// returns 0.
int Object_000A1C50::func_00093BB0()
{
    value_cd4 *= 0.5f;
    value_11c = 0xa3;
    value_118 = 1;
    func_00092FF0(data->value, 1, 1, 1);
    return 0;
}
