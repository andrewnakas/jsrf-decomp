int func_0004EB80(int player, unsigned int mask);
void func_000FE4E0(int kind, int id, int argument);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xa80];
    int value_a80;
    char unknown_a84[0x218];
    int value_c9c;
    char unknown_ca0[0x31c];
    int id_fbc;

    unsigned int func_0007F9B0(unsigned int range);
    void func_0009BD30();
};

// With 0x4b0 at 0xa80, 0xc9c clear and func_0004EB80(1, 8), passes 0x2f or 0x30 (even odds, func_0007F9B0) with the
// id at 0xfbc to func_000FE4E0.
void Object_000A1C50::func_0009BD30()
{
    if (value_a80 == 0x4b0 && !value_c9c && func_0004EB80(1, 8)) {
        if (func_0007F9B0(100) < 50) {
            func_000FE4E0(0x2f, id_fbc, 0);
        } else {
            func_000FE4E0(0x30, id_fbc, 0);
        }
    }
}
