// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xa78];
    unsigned int flags_a78;
    char unknown_a7c[0x44];
    int value_ac0;
    char unknown_ac4[0x1f8];
    int value_cbc;
    char unknown_cc0[4];
    int value_cc4;
    char unknown_cc8[0xc];
    float value_cd4;
    char unknown_cd8[0x448];
    int value_1120;

    void func_00099FC0();
};

void Object_000A1C50::func_00099FC0()
{
    value_cbc = 0;
    value_cc4 = 0;
    if (value_1120 > 0) {
        if (value_cd4 < 0.0f) {
            value_ac0 = 0;
        } else {
            value_ac0 = value_1120;
        }
    } else if (flags_a78 & 0x2000) {
        value_ac0 = -value_1120;
    } else if (value_cd4 < 0.0f) {
        value_ac0 = value_1120;
    } else {
        value_ac0 = 0;
    }
}
