struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

struct Object_000A1C50 {
    char unknown_000[0xc90];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float value_cd4;

    void func_00092810();
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093A90();
};

// Negates the value at 0xcd4 (`fchs`), runs func_00092810 and func_00092FF0(data->value, 1, 1, 1); returns 0.
int Object_000A1C50::func_00093A90()
{
    value_cd4 = -value_cd4;
    func_00092810();
    func_00092FF0(data->value, 1, 1, 1);
    return 0;
}
