int func_0004EB80(int player, unsigned int mask);
void func_000FE4E0(int kind, int id, int argument);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc9c];
    int value_c9c;
    char unknown_ca0[0x31c];
    int id;
    char unknown_fc0[0x10c];
    int count;

    void func_0009BCA0();
};

// Counts at 0x10cc; on the 20th, when func_0004EB80 reports 2 for player 1 and 0xc9c is clear, func_000FE4E0 with
// 0x1d and the id at 0xfbc.
void Object_000A1C50::func_0009BCA0()
{
    count++;
    if (func_0004EB80(1, 2) && !value_c9c && count == 20) {
        func_000FE4E0(0x1d, id, 0);
    }
}
