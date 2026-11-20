struct Entry_002104A0 {
    char unknown_00[0xc];
    int value;
    char unknown_10[0x20];
};

struct Data_00093920 {
    char unknown_00[0x24];
    int value;
};

struct Object_000A1C50 {
    char unknown_000[0xa94];
    int value_a94;
    char unknown_a98[0x6c];
    int value_b04;
    char unknown_b08[0x188];
    Data_00093920 *data;
    char unknown_c94[0x40];
    float value_cd4;
    char unknown_cd8[0x180];
    int phase;

    void func_00092810();
    void func_00092FF0(int value, int kind, int mode, int flag);
    void func_0009E8E0(int first, int second);
    Entry_002104A0 *func_000A0120(int index);
    float func_000A0280(int index);
    int func_00093610();
};

// Turns the value at 0xcd4 around, phase 3, 0x78 at 0xa94 and 1 at 0xb04; then like func_00093880 with entry
// 0xa5: func_0009E8E0, func_00092810 and func_00092FF0(data->value, 0, 1, 0); returns 0.
int Object_000A1C50::func_00093610()
{
    value_cd4 *= -1.0f;
    phase = 3;
    value_a94 = 0x78;
    value_b04 = 1;
    Entry_002104A0 *entry = func_000A0120(0xa5);
    func_0009E8E0(entry->value, (int)func_000A0280(entry->value));
    func_00092810();
    func_00092FF0(data->value, 0, 1, 0);
    return 0;
}
