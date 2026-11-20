int func_0004A7F0(int value, int divisor);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xa84];
    int value_a84;
    char unknown_a88[0x124];
    int value_bac;
    int side;
    char unknown_bb4[0x10c];
    int value_cc0;
    char unknown_cc4[0x464];
    int value_1128;

    void func_00098970();
};

// The side at 0xbb0: 0, unless the value at 0xa84 is over 0x1555; then, with 0x1128 turned half a turn (kept at
// 0xbac), func_0004A7F0 of 0xcc0 and that below -0x222 gives 1 and above 0x222 gives 2.
void Object_000A1C50::func_00098970()
{
    side = 0;
    if (value_a84 > 0x1555) {
        value_bac = value_1128 + 0x8000;
        int difference = func_0004A7F0(value_cc0, value_bac);
        if (difference < -0x222) {
            side = 1;
        } else if (difference > 0x222) {
            side = 2;
        }
    }
}
