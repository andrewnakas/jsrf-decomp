int func_0004EB80(int player, unsigned int mask);
void func_000FE4E0(int kind, int id, int argument);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc9c];
    int value_c9c;
    char unknown_ca0[0x31c];
    int id;

    unsigned int func_0007F9B0(unsigned int range);
    void func_0009BEB0();
};

// Unless 0xc9c is set: when func_0004EB80 reports 0x80 for player 1, func_000FE4E0 with 0x48 or 0x49 (an even
// draw of func_0007F9B0) and the id at 0xfbc.
void Object_000A1C50::func_0009BEB0()
{
    if (!value_c9c && func_0004EB80(1, 0x80)) {
        if (func_0007F9B0(100) < 50) {
            func_000FE4E0(0x48, id, 0);
        } else {
            func_000FE4E0(0x49, id, 0);
        }
    }
}
