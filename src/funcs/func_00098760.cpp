int func_0004A820(int current, int target, int step);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xcc0];
    int value_cc0;
    char unknown_cc4[0x464];
    int value_1128;

    void func_00098760(int amount);
};

// Moves 0xcc0 toward 0x1128 by a sixtieth of the amount (func_0004A820).
void Object_000A1C50::func_00098760(int amount)
{
    int target = value_1128;
    value_cc0 = func_0004A820(value_cc0, target, amount / 60);
}
