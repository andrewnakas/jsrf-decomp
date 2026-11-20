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

    unsigned int func_0007F9B0(unsigned int range);
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093EC0();
};

// 0xa1 or 0xa2 at 0x11c by an even draw of func_0007F9B0(100), 1 at 0x118, then
// func_00092FF0(data->value_38, 0, 5, 1); returns 0.
int Object_000A1C50::func_00093EC0()
{
    value_11c = func_0007F9B0(100) < 50 ? 0xa1 : 0xa2;
    value_118 = 1;
    func_00092FF0(data->value_38, 0, 5, 1);
    return 0;
}
