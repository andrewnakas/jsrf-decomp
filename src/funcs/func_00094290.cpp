struct Data_00093920 {
    char unknown_00[0x34];
    int value_34;
};

struct Object_000A1C50 {
    char unknown_000[0xc60];
    int value_c60;
    char unknown_c64[0x2c];
    Data_00093920 *data;
    char unknown_c94[0x1c4];
    int phase;

    void func_00092FF0(int value, int kind, int mode, int flag);
    void func_0009E8E0(int first, int second);
    int func_00094290(int index, int unused);
};

// A handler with two arguments, which it does not use: phase 3, func_00092FF0 with the data's value at 0x34,
// 4, 3, 1, then 0xb4 at 0xc60 and func_0009E8E0(0xee, 0xb4); returns 0.
int Object_000A1C50::func_00094290(int, int)
{
    phase = 3;
    func_00092FF0(data->value_34, 4, 3, 1);
    value_c60 = 0xb4;
    func_0009E8E0(0xee, 0xb4);
    return 0;
}
