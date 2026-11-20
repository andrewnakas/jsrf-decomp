struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;
    char unknown_11c[0xb74];
    Data_00093920 *data;

    void func_0008D1E0();
    void func_000A1FC0();
    void func_000A23D0();
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093A10();
};

// Like func_00093720, then func_00092FF0(data->value, 1, 1, 0); returns 0.
int Object_000A1C50::func_00093A10()
{
    func_0008D1E0();
    func_000A23D0();
    func_000A1FC0();
    value_118 = 1;
    func_00092FF0(data->value, 1, 1, 0);
    return 0;
}
