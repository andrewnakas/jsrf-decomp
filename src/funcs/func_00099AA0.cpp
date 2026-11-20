// The object at 0x2a0 of the player.
struct Object_00094780 {
    char unknown_00[0x10c];
    float value_10c;
    float value_110;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x2a0];
    Object_00094780 *object_2a0;
    char unknown_2a4[0xa30];
    float speed;
    char unknown_cd8[4];
    float value_cdc;

    int func_000836A0();
    void func_000992D0(int first, int second, int third, float value);
    void func_00099F10();
    int func_00099AA0();
};

// When func_000836A0 allows it, takes the size of 0xcdc as the speed and passes it, less the two values at 0x10c and
// 0x110 of the object at 0x2a0 (not below 0), to func_000992D0(1, 0, 1, ...); otherwise func_00099F10. Returns 1.
int Object_000A1C50::func_00099AA0()
{
    if (func_000836A0()) {
        speed = value_cdc < 0.0f ? -value_cdc : value_cdc;
        float rest = (value_cdc < 0.0f ? -value_cdc : value_cdc) - object_2a0->value_10c - object_2a0->value_110;
        if (rest < 0.0f) {
            rest = 0.0f;
        }
        func_000992D0(1, 0, 1, rest);
        return 1;
    }
    func_00099F10();
    return 1;
}
