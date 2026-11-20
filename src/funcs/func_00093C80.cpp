struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;
    int value_11c;
    char unknown_120[0xb70];
    Data_00093920 *data;

    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093C80();
};

// Sets the field at 0x11c to 161 and the one at 0x118 to 1, then func_00092FF0(data->value, 0, 1, 1);
// returns 0.
int Object_000A1C50::func_00093C80()
{
    value_11c = 0xa1;
    value_118 = 1;
    func_00092FF0(data->value, 0, 1, 1);
    return 0;
}
