// The object at 0x2a0 of the player.
struct Data_00092300 {
    char unknown_00[0xf0];
    float scale;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x11c];
    int value_11c;
    char unknown_120[0xc];
    float value_12c;
    char unknown_130[0x170];
    Data_00092300 *data_2a0;
    char unknown_2a4[0x9b8];
    int value_c5c;
    char unknown_c60[0x74];
    float speed;
    char unknown_cd8[0x178];
    int value_e50;

    int func_000A02E0();
    void func_00091930();
};

// A handler of the player's tables: 0x12c is minus the speed at 0xcd4 over the scale at 0xf0 of 0x2a0, 0xe50 = 9,
// 0xc5c cleared, and 0x11c is 0x98 when func_000A02E0 holds, else 0x9b.
void Object_000A1C50::func_00091930()
{
    value_12c = -(speed / data_2a0->scale);
    value_e50 = 9;
    value_c5c = 0;
    value_11c = func_000A02E0() ? 0x98 : 0x9b;
}
