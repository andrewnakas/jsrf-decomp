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

    int func_00091EB0();
    void func_00092910(int first, int second);
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093810();
};

// Runs func_00092910 with the fields at 0x298 and 0x29c and func_00092FF0(data->value, 1, 1, 0), then returns
// func_00091EB0().
int Object_000A1C50::func_00093810()
{
    func_00092910(value_298, value_29c);
    func_00092FF0(data->value, 1, 1, 0);
    return func_00091EB0();
}
