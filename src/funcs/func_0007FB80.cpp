int func_0004A7F0(int first, int second);

// One entry of the player's parameter table (0x98 bytes).
struct Limit_0007F9E0 {
    int value;
    char unknown_04[0x94];
};

struct Table_0007F9E0 {
    char unknown_000[0x100];
    Limit_0007F9E0 limits[1];
};

// The player.
struct Object_000A1C50 {
    char unknown_000[0xd0];
    int angle_d0;
    char unknown_0d4[0x5c];
    float lean;
    char unknown_134[0xb5c];
    Table_0007F9E0 *table;
    char unknown_c94[0x2c];
    int angle_cc0;
    char unknown_cc4[0x4a4];
    int index;

    int func_0007FB80();
};

// Leans (+0x130, by 0.1 up to 1 or down to -1) towards the side the heading at +0xcc0 turns from +0xd0
// (func_0004A7F0) when the turn is at least 0x2aaa and within the limit of the player's table entry. Returns 1 when
// it leaned.
int Object_000A1C50::func_0007FB80()
{
    int leaned = 0;
    int turn = func_0004A7F0(angle_cc0, angle_d0);
    if (turn <= -0x2aaa && (turn < 0 ? -turn : turn) >= -table->limits[index].value) {
        lean += 0.1f;
        if (lean > 1.0f) {
            lean = 1.0f;
        }
        leaned = 1;
    }
    if (turn >= 0x2aaa && (turn < 0 ? -turn : turn) <= table->limits[index].value) {
        lean -= 0.1f;
        if (lean < -1.0f) {
            lean = -1.0f;
        }
        return 1;
    }
    return leaned;
}
