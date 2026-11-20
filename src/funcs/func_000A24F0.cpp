struct Data_00093920 {
    char unknown_00[0x64];
    float value_64;
};

// The object at 0x2a0 of the player.
struct Object_00094780 {
    char unknown_00[0xb4];
    int value_b4;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x11c];
    int value_11c;
    char unknown_120[0x180];
    Object_00094780 *object_2a0;
    char unknown_2a4[0x768];
    int value_a0c;
    char unknown_a10[0x154];
    int value_b64;
    char unknown_b68[0x128];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float speed;
    char unknown_cd8[4];
    float value_cdc;
    char unknown_ce0[0x120];
    int value_e00;
    char unknown_e04[0x4c];
    int value_e50;
    char unknown_e54[4];
    int phase;
    char unknown_e5c[0x218];
    int value_1074;

    void func_0009C210();
    void func_0009C240();
    void func_000A1CF0();
    void func_000A22F0();
    void func_000A24F0(int unused);
};

// Phase 4 (unless 9), 0xb64 from the object at 0x2a0, 0xcdc cleared, the speed scaled by the data's value at 0x64,
// 0x50 (0x55 without 0xe00) at 0x11c; func_000A22F0, func_000A1CF0, func_0009C210, func_0009C240; counts 0x1074 up,
// clears 0xa0c and puts 4 at 0xe50.
void Object_000A1C50::func_000A24F0(int)
{
    if (phase != 9) {
        phase = 4;
    }
    value_b64 = object_2a0->value_b4;
    value_cdc = 0.0f;
    speed = data->value_64 * speed;
    value_11c = value_e00 ? 0x50 : 0x55;
    func_000A22F0();
    func_000A1CF0();
    func_0009C210();
    func_0009C240();
    value_1074++;
    value_a0c = 0;
    value_e50 = 4;
}
