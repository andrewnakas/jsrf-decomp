// An entry of the registry at data_002314B0: a value at 0xc8.
struct Entry_0003E720 {
    char unknown_00[0xc8];
    float value_c8;
};

struct Object_0003E750 {
    Entry_0003E720 *func_0003E720(int key);
};

extern Object_0003E750 data_002314B0;

// The player's table at 0xc90: a speed factor at 0x64.
struct Table_00098100 {
    char unknown_00[0x64];
    float factor;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x11c];
    int kind_11c;
    char unknown_120[0x8ec];
    int value_a0c;
    char unknown_a10[0x54];
    int value_a64;
    char unknown_a68[0x98];
    int value_b00;
    char unknown_b04[8];
    float value_b0c;
    char unknown_b10[0x2c];
    int value_b3c;
    int value_b40;
    int value_b44;
    int value_b48;
    int value_b4c;
    int value_b50;
    float value_b54;
    char unknown_b58[0x14];
    int value_b6c;
    char unknown_b70[0xd4];
    int value_c44;
    char unknown_c48[0x48];
    Table_00098100 *table;
    char unknown_c94[0x40];
    float speed;
    char unknown_cd8[0x178];
    int value_e50;
    char unknown_e54[4];
    int state_e58;
    char unknown_e5c[0x18];
    int value_e74;
    char unknown_e78[0x9c];
    int value_f14;
    char unknown_f18[0x124];
    int linked;
    int linkKey;
    char unknown_1044[0x18];
    int value_105c;
    char unknown_1060[0x18];
    int value_1078;
    char unknown_107c[0x24];
    int value_10a0;
    int value_10a4;
    char unknown_10a8[0x24];
    int value_10cc;
    char unknown_10d0[0x78];
    int value_1148;

    float func_00098090();
    void func_0009BB10();
    void func_0009BF70(int kind, int flag);
    void func_0009BFE0(int value);
    void func_0009C550(int state);
    int func_000A0370();
    void func_000A1CF0();
    void func_00098100(int argument);
};

// Moves to state 0x16 (func_0009C550) when 0xc44 is set or the entry the key at 0x1040 names (with 0x103c set) has
// no value left, unless 0xf14 is set. Otherwise leaves state 9 alone or sets 5, scales the speed at 0xcd4 by the
// table's factor and keeps it at least 0.926 either way from 0, and resets the movement (kind at 0x11c from
// func_000A0370, func_00098090 at 0xb0c, the counters at 0xb3c to 0xb54, func_0009BB10, func_0009BF70,
// func_0009BFE0(1), func_000A1CF0) and clears the words at 0x105c to 0x10cc, 0xa0c and 0xa64. The argument is not read.
void Object_000A1C50::func_00098100(int)
{
    Entry_0003E720 *entry;
    if ((value_c44 && !value_f14) ||
        (linked && (entry = data_002314B0.func_0003E720(linkKey)) != 0 && entry->value_c8 <= 0.0f && !value_f14)) {
        func_0009C550(0x16);
        return;
    }
    if (state_e58 != 9) {
        state_e58 = 5;
    }
    value_b6c = 0;
    value_b00 = 0xc;
    speed = table->factor * speed;
    if (speed < 0.9259259f && speed >= 0.0f) {
        speed = 0.9259259f;
    }
    if (speed > -0.9259259f && speed < 0.0f) {
        speed = -0.9259259f;
    }
    int kind = func_000A0370();
    kind_11c = kind;
    value_b0c = func_00098090();
    value_b54 = 0.0077160494f;
    value_b50 = 0;
    value_b3c = 0;
    value_b44 = 0;
    value_b48 = 0;
    value_b4c = 0x3c;
    value_b40 = 0x3c;
    value_e74 = 0;
    value_e50 = 3;
    func_0009BB10();
    if (value_1148) {
        func_0009BF70(kind, 1);
    } else {
        func_0009BF70(kind, 0);
    }
    func_0009BFE0(1);
    func_000A1CF0();
    value_105c = 0;
    value_1078 = 0;
    value_10a0 = 0;
    value_10a4 = 0;
    value_10cc = 0;
    value_a0c = 0;
    value_a64 = 0;
}
