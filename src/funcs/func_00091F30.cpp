struct Data_00093920 {
    char unknown_00[0x44];
    int value_44;
};

// The object at 0x2a0 of the player.
struct Object_00094780 {
    char unknown_00[0xf4];
    float value_f4;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x11c];
    int value_11c;
    char unknown_120[0xc];
    float value_12c;
    char unknown_130[0x170];
    Object_00094780 *object_2a0;
    char unknown_2a4[0x860];
    int value_b04;
    char unknown_b08[0x154];
    int value_c5c;
    char unknown_c60[0x30];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float value_cd4;
    char unknown_cd8[0x178];
    int value_e50;
    char unknown_e54[4];
    int value_e58;

    void func_000A0DA0();
    void func_00092FF0(int value, int kind, int mode, int flag);
    int func_00091F30();
};

// State 3 at 0xe58, 0xcd4 over the value at 0xf4 of the object at 0x2a0 into 0x12c, 1 at 0xb04, 0xcd4 negated;
// func_000A0DA0; 9 at 0xe50, 0 at 0xc5c, 0x95 at 0x11c; func_00092FF0(data->value_44, 2, 2, 1); returns 1.
int Object_000A1C50::func_00091F30()
{
    value_e58 = 3;
    value_12c = value_cd4 / object_2a0->value_f4;
    value_b04 = 1;
    value_cd4 *= -1.0f;
    func_000A0DA0();
    value_e50 = 9;
    value_c5c = 0;
    value_11c = 0x95;
    func_00092FF0(data->value_44, 2, 2, 1);
    return 1;
}
