int func_0004A7F0(int value, int divisor);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xba4];
    int value_ba4;
    char unknown_ba8[0x114];
    int value_cbc;
    int value_cc0;
    int value_cc4;
    char unknown_cc8[0x460];
    int value_1128;
    char unknown_112c[0x24];
    int value_1150;
    int value_1154;
    int value_1158;
    int value_115c;

    void func_00098910();
};

// Copies 0xcbc and 0xcc4 to 0x1150 and 0x1154, and 0x1128 to 0x1158 (and 0x8000 past it to 0x115c); 0xba4 is
// 0x1128 less func_0004A7F0 of 0x1128 and 0xcc0.
void Object_000A1C50::func_00098910()
{
    value_1150 = value_cbc;
    value_1154 = value_cc4;
    value_1158 = value_1128;
    value_115c = value_1128 + 0x8000;
    value_ba4 = value_1128 - func_0004A7F0(value_1128, value_cc0);
}
