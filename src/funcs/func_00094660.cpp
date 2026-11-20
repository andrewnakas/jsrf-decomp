struct Data_00093920 {
    char unknown_00[0x24];
    int value;
    char unknown_28[0x88];
    int value_b0;
};

struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;
    int value_11c;
    char unknown_120[0x178];
    int value_298;
    int value_29c;
    char unknown_2a0[0x9b4];
    int value_c54;
    char unknown_c58[0xc];
    int value_c64;
    char unknown_c68[0x28];
    Data_00093920 *data;
    char unknown_c94[0x2c];
    int value_cc0;
    char unknown_cc4[0x10];
    int value_cd4;
    char unknown_cd8[0x498];
    int value_1170;
    int value_1174;

    void func_00092910(int first, int second);
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00094660();
};

// 0xa3 at 0x11c, the value at 0xb0 of the data into 0xcd4 and 0xc64, 0x3c and 0xb4 at 0x1170 and 0x1174, 0xc54
// copied to 0xcc0 and 1 at 0x118; then func_00092910 with the fields at 0x298 and 0x29c and
// func_00092FF0(data->value, 1, 6, 0); returns 0.
int Object_000A1C50::func_00094660()
{
    value_11c = 0xa3;
    value_cd4 = data->value_b0;
    value_1170 = 0x3c;
    value_c64 = value_cd4;
    value_1174 = 0xb4;
    value_cc0 = value_c54;
    value_118 = 1;
    func_00092910(value_298, value_29c);
    func_00092FF0(data->value, 1, 6, 0);
    return 0;
}
