struct Data_00093920 {
    char unknown_00[0x14];
    float value_14;
};

// The object at 0x2a0 of the player.
struct Object_00094780 {
    int value_00;
    char unknown_04[0xec];
    float value_f0;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x11c];
    int value_11c;
    char unknown_120[0xc];
    float value_12c;
    char unknown_130[0x170];
    Object_00094780 *object_2a0;
    char unknown_2a4[0x9a0];
    int value_c44;
    char unknown_c48[0x20];
    float value_c68;
    float value_c6c;
    char unknown_c70[0x20];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float value_cd4;
    char unknown_cd8[0x148];
    int value_e20;
    char unknown_e24[0x2c];
    int value_e50;
    char unknown_e54[4];
    int value_e58;
    char unknown_e5c[0xb8];
    int value_f14;

    void func_0009C550(int value);
    void func_00092ED0();
};

// With 0xc44 set and 0xf14 clear, func_0009C550(0x16); otherwise 0x11 and 3 at 0xe50 and 0xe58, 60 times the
// data's value at 0x14 into 0xc68, 0xcd4 halved and minus it over the value at 0xf0 of the object at 0x2a0 into
// 0x12c, 1 at 0xc6c, that object's first value into 0xe20 and 0xa6 at 0x11c.
void Object_000A1C50::func_00092ED0()
{
    if (value_c44 && !value_f14) {
        func_0009C550(0x16);
        return;
    }
    value_e50 = 0x11;
    value_e58 = 3;
    value_c68 = data->value_14 * 60.0f;
    value_cd4 *= 0.5f;
    value_12c = -(value_cd4 / object_2a0->value_f0);
    value_c6c = 1.0f;
    value_e20 = object_2a0->value_00;
    value_11c = 0xa6;
}
