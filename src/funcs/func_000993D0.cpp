// One 0x98-byte entry of the player's table at 0xc90.
struct Entry_000993D0 {
    char unknown_00[0x38];
    int lowCount;
    float lowSpeed;
    int lowValue;
    char unknown_44[4];
    int highCount;
    float highSpeed;
    int highTime;
    char unknown_54[0x44];
};

// The player's table at 0xc90: its entries from 0xa0.
struct Table_000993D0 {
    char unknown_00[0xa0];
    Entry_000993D0 entries[1];
};

int func_0004A820(int value, int first, int second);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;
    int value_11c;
    char unknown_120[0x964];
    int count;
    char unknown_a88[0x120];
    int seenCount;
    char unknown_bac[0x10];
    int state_bbc;
    char unknown_bc0[0xd0];
    Table_000993D0 *table;
    char unknown_c94[0x2c];
    int value_cc0;
    char unknown_cc4[0x10];
    float value_cd4;
    char unknown_cd8[0x450];
    int value_1128;
    char unknown_112c[0x3c];
    int entry;

    float func_0007F820();
    void func_00098760(int value);
    void func_00098800();
    void func_00098970();
    void func_000989D0();
    void func_000993D0();
};

// When the count at 0xa84 changed since 0xba8, func_00098970 first. Past the entry's high count: with the speed at
// 0xcd4 at least the entry's high speed and some input (func_0007F820), func_000989D0; else 0xcc0 becomes
// func_0004A820 of it, 0x1128 and the entry's time over 60; past the low count likewise with func_00098760 of the
// entry's low value; else func_000989D0 alone. 0xbbc is 0x77 after the first two. Then func_00098800, 0x11c = 10 and
// 0x118 = 1 when 0xbbc is 0, and 0xba8 takes the count.
void Object_000A1C50::func_000993D0()
{
    if (seenCount != count) {
        func_00098970();
        seenCount = count;
    }
    if (count > table->entries[entry].highCount) {
        if (!(value_cd4 < table->entries[entry].highSpeed) && func_0007F820() != 0.0f) {
            func_000989D0();
        } else {
            int other = value_1128;
            value_cc0 = func_0004A820(value_cc0, other, table->entries[entry].highTime / 60);
        }
        state_bbc = 0x77;
    } else if (count > table->entries[entry].lowCount) {
        if (!(value_cd4 < table->entries[entry].lowSpeed) && func_0007F820() != 0.0f) {
            func_000989D0();
        } else {
            func_00098760(table->entries[entry].lowValue);
        }
        state_bbc = 0x77;
    } else {
        func_000989D0();
    }
    func_00098800();
    if (state_bbc == 0) {
        value_11c = 10;
        value_118 = 1;
    }
    seenCount = count;
}
