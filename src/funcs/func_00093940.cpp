struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

struct Object_000A1C50 {
    char unknown_000[0xc90];
    Data_00093920 *data;

    int func_00091FC0();
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093940();
};

// Runs func_00092FF0(data->value, 1, 1, 0) like its neighbour func_00093920, then returns func_00091FC0().
int Object_000A1C50::func_00093940()
{
    func_00092FF0(data->value, 1, 1, 0);
    return func_00091FC0();
}
