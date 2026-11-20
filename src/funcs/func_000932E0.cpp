/* const: 0x10000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

int func_0004A7F0(int first, int second);
int func_0004A820(int value, int first, int second);
float func_0014C7F0(float value);

// One 0x98-byte entry of the player's table at 0xc90.
struct Entry_000932E0 {
    char unknown_00[0x18];
    float limit;
    char unknown_1c[0x44];
    int range;
    float base;
    float scale;
    char unknown_6c[0x2c];
};

// The player's table at 0xc90: two rates at 0x18 and 0x1c, its entries from 0xa0.
struct Table_000932E0 {
    char unknown_00[0x18];
    float rate;
    float heldRate;
    char unknown_20[0x80];
    Entry_000932E0 entries[1];
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x118];
    int value_118;
    int kind_11c;
    char unknown_120[0xb48];
    float value_c68;
    char unknown_c6c[0x24];
    Table_000932E0 *table;
    char unknown_c94[0x2c];
    int value_cc0;
    char unknown_cc4[0x10];
    float speed;
    char unknown_cd8[0x178];
    int value_e50;
    char unknown_e54[0x314];
    int entry;

    float func_0007F820();
    int func_0007F850();
    int func_0007F880();
    void func_0007F8B0(int turn, float share);
    void func_0007FD20();
    void func_00089E00();
    int func_0008EAA0(int *result, Vector3 *point);
    int func_00091380(int *first, int *second);
    void func_000932E0();
};

// A player step: func_00089E00, func_00091380, func_0008EAA0, func_0007FD20; with input above 0.5 (func_0007F820)
// and 0x118 clear, turns toward func_0007F850 (func_0007F8B0 with the turn and its share of the entry's range, then
// 0xcc0 moved on by func_0004A820 at 1820 times the entry's base plus scale times what is left of its limit after
// func_0014C7F0 of the speed), sets the speed to 0.2315 and kind 0xa8; otherwise stops with kind 0xa7. Then runs
// down 0xc68 by 60 times the table's rate (0x1c with input bit 16 of func_0007F880, else 0x18) and at 0 stops with
// kind 0xa9 and 0xe50 = 0x13.
void Object_000A1C50::func_000932E0()
{
    func_00089E00();
    int first;
    int second;
    func_00091380(&second, &first);
    int result = 0;
    func_0008EAA0(&result, 0);
    func_0007FD20();
    if (func_0007F820() > 0.5f && !value_118) {
        float rate = (1.0f - func_0014C7F0(speed) / table->entries[entry].limit) * table->entries[entry].scale +
                     table->entries[entry].base;
        speed = 0.23148148f;
        int turn = func_0004A7F0(func_0007F850(), value_cc0);
        int size = turn < 0 ? -turn : turn;
        func_0007F8B0(turn, size / (float)table->entries[entry].range);
        value_cc0 = func_0004A820(value_cc0, func_0007F850(), (int)(rate * 1820.0f));
        kind_11c = 0xa8;
    } else {
        speed = 0.0f;
        kind_11c = 0xa7;
    }
    if (func_0007F880() & 0x10000) {
        value_c68 -= table->heldRate * 60.0f;
    } else {
        value_c68 -= table->rate * 60.0f;
    }
    if (value_c68 <= 0.0f) {
        speed = 0.0f;
        kind_11c = 0xa9;
        value_e50 = 0x13;
    }
}
