struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;
    int value_11c;
    char unknown_120[0x974];
    int value_a94;
    char unknown_a98[0x6c];
    int value_b04;
    char unknown_b08[0x188];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float value_cd4;
    char unknown_cd8[0x180];
    int value_e58;

    void func_00092810();
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093520();
};

// State 3 at 0xe58 with the value at 0xcd4 negated, 0x78 at 0xa94, 1 at 0xb04, 0x91 and 1 at 0x11c and 0x118;
// then func_00092810 and func_00092FF0(data->value, 1, 1, 0); returns 0.
int Object_000A1C50::func_00093520()
{
    value_e58 = 3;
    value_cd4 *= -1.0f;
    value_a94 = 0x78;
    value_b04 = 1;
    value_11c = 0x91;
    value_118 = 1;
    func_00092810();
    func_00092FF0(data->value, 1, 1, 0);
    return 0;
}
