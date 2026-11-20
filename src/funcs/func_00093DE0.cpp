struct Data_00093920 {
    char unknown_00[0x38];
    int value_38;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;
    int value_11c;
    char unknown_120[0xb70];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float speed;

    unsigned int func_0007F9B0(unsigned int range);
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00093DE0();
};

// A handler of the player's tables: 0x11c is 0xa4 or 0xa5 (an even draw of func_0007F9B0), the speed at 0xcd4
// halves, 0x118 = 1, and func_00092FF0 with the value at 0x38 of 0xc90, 0, 5 and 1. Returns 0.
int Object_000A1C50::func_00093DE0()
{
    value_11c = func_0007F9B0(100) < 50 ? 0xa4 : 0xa5;
    speed *= 0.5f;
    value_118 = 1;
    func_00092FF0(data->value_38, 0, 5, 1);
    return 0;
}
