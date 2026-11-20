struct Data_00093920 {
    char unknown_00[0x24];
    int value;
    char unknown_28[4];
    int value_2c;
    int value_30;
    char unknown_34[4];
    int value_38;
    int value_3c;
};

struct Object_000A1C50 {
    char unknown_000[0x298];
    int value_298;
    int value_29c;
    char unknown_2a0[0x9b4];
    int value_c54;
    char unknown_c58[0xc];
    float value_c64;
    char unknown_c68[0x28];
    Data_00093920 *data;
    char unknown_c94[0x2c];
    int value_cc0;
    char unknown_cc4[0x10];
    float value_cd4;
    char unknown_cd8[0x498];
    int value_1170;
    int value_1174;

    void func_00092910(int first, int second);
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_000923A0();
    int func_00093D40();
};

// func_00092910 with the fields at 0x298 and 0x29c, func_00092FF0(data->value, 1, 6, 0), the field at 0xc54
// copied to 0xcc0, 0xb4 at 0x1174, then returns func_000923A0().
int Object_000A1C50::func_00093D40()
{
    func_00092910(value_298, value_29c);
    func_00092FF0(data->value, 1, 6, 0);
    value_cc0 = value_c54;
    value_1174 = 0xb4;
    return func_000923A0();
}
