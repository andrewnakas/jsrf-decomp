struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

struct Object_000A1C50 {
    char unknown_000[0xc90];
    Data_00093920 *data;

    int func_00092060();
    void func_00092810();
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093850();
};

// func_00092810 and func_00092FF0(data->value, 1, 1, 1), then returns func_00092060().
int Object_000A1C50::func_00093850()
{
    func_00092810();
    func_00092FF0(data->value, 1, 1, 1);
    return func_00092060();
}
