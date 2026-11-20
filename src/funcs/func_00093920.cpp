struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

struct Object_00092FF0 {
    char unknown_000[0xc90];
    Data_00093920 *data;

    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093920();
};

int Object_00092FF0::func_00093920()
{
    func_00092FF0(data->value, 1, 1, 0);
    return 0;
}
