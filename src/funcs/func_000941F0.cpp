struct Data_00093920 {
    char unknown_00[0x24];
    int value;
    char unknown_28[4];
    int value_2c;
    int value_30;
    char unknown_34[4];
    int value_38;
    int value_3c;
};

struct Object_000A1C50 {
    char unknown_000[0xc54];
    int value_c54;
    char unknown_c58[0x38];
    Data_00093920 *data;
    char unknown_c94[0x2c];
    int value_cc0;
    char unknown_cc4[0x194];
    int phase;

    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_000941F0(int index, int unused);
};

extern int (Object_000A1C50::*data_0020E32C[])();

// A two-argument handler: phase 3, func_00092FF0(data->value_30, 2, 4, 1), the field at 0xc54 copied to 0xcc0,
// then returns the handler the table at 0x20e32c holds for the index.
int Object_000A1C50::func_000941F0(int index, int)
{
    phase = 3;
    func_00092FF0(data->value_30, 2, 4, 1);
    value_cc0 = value_c54;
    return (this->*data_0020E32C[index])();
}
