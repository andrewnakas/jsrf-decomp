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
    char unknown_2a4[0x860];
    int value_b04;
    char unknown_b08[0x154];
    int value_c5c;
    char unknown_c60[0x74];
    float speed;
    char unknown_cd8[0x178];
    int value_e50;
    char unknown_e54[4];
    int value_e58;

    int func_00092350();
};

// A move of the player's tables: 0x11c = 0x92, 0xe58 = 3, 0xe50 = 9, 0xb04 = 1, 0xc5c cleared; 0x12c is minus the speed
// at 0xcd4 over the scale at 0xf0 of 0x2a0. Returns 1.
int Object_000A1C50::func_00092350()
{
    value_e58 = 3;
    value_12c = -(speed / data_2a0->scale);
    value_b04 = 1;
    value_e50 = 9;
    value_c5c = 0;
    value_11c = 0x92;
    return 1;
}
