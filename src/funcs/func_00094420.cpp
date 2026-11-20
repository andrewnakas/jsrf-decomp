struct Data_00093920 {
    char unknown_00[0x24];
    int value_24;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;
    int value_11c;
    char unknown_120[0x178];
    int value_298;
    int value_29c;
    char unknown_2a0[0x9c4];
    float value_c64;
    char unknown_c68[0x28];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float speed;
    char unknown_cd8[0x498];
    int value_1170;

    void func_00092910(int first, int second);
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00094420();
};

// A handler of the player's tables: 0x11c = 0x94, 0x1170 = 60, the speed at 0xcd4 kept at 0xc64, 0x118 = 1,
// func_00092910 with 0x298 and 0x29c, and func_00092FF0 with the value at 0x24 of 0xc90, 1, 1 and 0. Returns 0.
int Object_000A1C50::func_00094420()
{
    value_11c = 0x94;
    value_1170 = 60;
    value_c64 = speed;
    value_118 = 1;
    func_00092910(value_298, value_29c);
    func_00092FF0(data->value_24, 1, 1, 0);
    return 0;
}
