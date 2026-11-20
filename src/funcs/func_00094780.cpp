struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

// The object at 0x2a0 of the player.
struct Object_00094780 {
    char unknown_00[0x80];
    int value_80;
};

struct Object_000A1C50 {
    char unknown_000[0x298];
    int value_298;
    int value_29c;
    Object_00094780 *object_2a0;
    char unknown_2a4[0x9c0];
    int value_c64;
    char unknown_c68[0x28];
    Data_00093920 *data;
    char unknown_c94[0x40];
    int value_cd4;
    char unknown_cd8[0x498];
    int value_1170;
    int value_1174;

    void func_00092910(int first, int second);
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00094780();
};

int Object_000A1C50::func_00094780()
{
    value_cd4 = object_2a0->value_80;
    value_1170 = 0x3c;
    value_c64 = value_cd4;
    value_1174 = 0xb4;
    func_00092910(value_298, value_29c);
    func_00092FF0(data->value, 1, 6, 0);
    return 0;
}
