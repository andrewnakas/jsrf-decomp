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
    char unknown_000[0x118];
    int value_118;
    int value_11c;
    char unknown_120[0x980];
    int value_aa0;
    char unknown_aa4[8];
    int value_aac;
    char unknown_ab0[0x1e0];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float value_cd4;
    char unknown_cd8[4];
    float value_cdc;

    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093C30();
};

// Clears the values at 0xcd4, 0xcdc and 0xaac, 0xa0 at 0x11c, 1 at 0x118, 2 at 0xaa0, then
// func_00092FF0(data->value, 1, 1, 1); returns 0.
int Object_000A1C50::func_00093C30()
{
    value_cd4 = 0.0f;
    value_cdc = 0.0f;
    value_aac = 0;
    value_11c = 0xa0;
    value_118 = 1;
    value_aa0 = 2;
    func_00092FF0(data->value, 1, 1, 1);
    return 0;
}
