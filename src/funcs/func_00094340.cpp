struct Entry_002104A0 {
    char unknown_00[0xc];
    int value;
    char unknown_10[0x20];
};

struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

struct Object_000A1C50 {
    char unknown_000[0x298];
    int value_298;
    int value_29c;
    char unknown_2a0[0x9f0];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float value_cd4;

    void func_00092910(int first, int second);
    void func_00092FF0(int value, int kind, int mode, int flag);
    void func_0009E8E0(int first, int second);
    Entry_002104A0 *func_000A0120(int index);
    float func_000A0280(int index);
    int func_00094340();
};

// Entry 0xa4 of the table of func_000A0120 to func_0009E8E0 like func_00093970, two thirds of the value at
// 0xcd4, func_00092910 with the fields at 0x298 and 0x29c, then func_00092FF0(data->value, 0, 1, 0); returns 0.
int Object_000A1C50::func_00094340()
{
    Entry_002104A0 *entry = func_000A0120(0xa4);
    func_0009E8E0(entry->value, (int)func_000A0280(entry->value));
    value_cd4 *= 0.6666667f;
    func_00092910(value_298, value_29c);
    func_00092FF0(data->value, 0, 1, 0);
    return 0;
}
