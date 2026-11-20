// The player's table at 0xc90: a value at 0x40.
struct Table_000A0610 {
    char unknown_00[0x40];
    int value_40;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;
    int kind_11c;
    int value_120;
    int value_124;
    int value_128;
    char unknown_12c[4];
    int value_130;
    int value_134;
    char unknown_138[0x898];
    int value_9d0;
    char unknown_9d4[8];
    int value_9dc;
    char unknown_9e0[0x2c];
    int value_a0c;
    char unknown_a10[0x64];
    int value_a74;
    char unknown_a78[8];
    int value_a80;
    char unknown_a84[0x80];
    int value_b04;
    char unknown_b08[0x64];
    int value_b6c;
    char unknown_b70[0x120];
    Table_000A0610 *table;
    char unknown_c94[0x40];
    float speed;
    char unknown_cd8[0x178];
    int value_e50;
    char unknown_e54[4];
    int state_e58;
    char unknown_e5c[0x18];
    int value_e74;
    char unknown_e78[0x1e8];
    int value_1060;
    int value_1064;
    char unknown_1068[0x14];
    int value_107c;
    int value_1080;
    char unknown_1084[0x34];
    int value_10b8;
    int value_10bc;
    int value_10c0;
    int value_10c4;
    char unknown_10c8[8];
    int value_10d0;
    int value_10d4;
    char unknown_10d8[0x4c];
    int value_1124;

    void func_0007EB10();
    int func_00092A00();
    void func_00092FF0(int first, int second, int third, int fourth);
    void func_0009C350();
    void func_000A1CF0();
    void func_000A2370();
    void func_000A2390();
    void func_000A0610(int kind);
};

// Leaves state 9 alone or sets 3 and clears the movement words. Kinds 2, 3, 4 and 8 set the kind at 0x11c (0x6c,
// 0x6f, 0x72, 0x7f), func_0007EB10, 0x118 = 1 and func_000A2370; kind 9 does the same with 0x7f after
// func_00092FF0(table 0x40, 3, 2, 1) and halves the speed at 0xcd4; kind 10 runs func_00092A00 and func_000A2390 and
// stops there. Otherwise func_000A1CF0, func_0009C350, moves 0x1060 and 0x107c on to the next words (clearing them),
// copies 0x10b8, 0x10c0 and 0x10d0 on, clears 0xa0c and sets 0xe50 to 1.
void Object_000A1C50::func_000A0610(int kind)
{
    if (state_e58 != 9) {
        state_e58 = 3;
    }
    value_1124 = 0;
    value_a74 = 0;
    value_9dc = 0;
    value_9d0 = 0;
    value_a80 = 0;
    value_b04 = 0;
    value_b6c = 0;
    value_120 = 0;
    value_124 = 0;
    value_128 = 0;
    value_118 = 0;
    value_e74 = 0;
    value_130 = 0;
    value_134 = 0;
    switch (kind) {
    case 2:
        kind_11c = 0x6c;
        func_0007EB10();
        value_118 = 1;
        func_000A2370();
        break;
    case 3:
        kind_11c = 0x6f;
        func_0007EB10();
        value_118 = 1;
        func_000A2370();
        break;
    case 4:
        kind_11c = 0x72;
        func_0007EB10();
        value_118 = 1;
        func_000A2370();
        break;
    case 8:
        kind_11c = 0x7f;
        func_0007EB10();
        value_118 = 1;
        func_000A2370();
        break;
    case 9:
        kind_11c = 0x7f;
        func_00092FF0(table->value_40, 3, 2, 1);
        func_0007EB10();
        speed *= 0.5f;
        value_118 = 1;
        func_000A2370();
        break;
    case 10:
        func_00092A00();
        func_000A2390();
        return;
    }
    func_000A1CF0();
    func_0009C350();
    value_1064 = value_1060;
    value_1080 = value_107c;
    value_a0c = 0;
    value_1060 = 0;
    value_107c = 0;
    value_e50 = 1;
    value_10bc = value_10b8;
    value_10c4 = value_10c0;
    value_10d4 = value_10d0;
}
