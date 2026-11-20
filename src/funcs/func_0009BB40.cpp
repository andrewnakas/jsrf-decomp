int func_0004EB80(int first, unsigned int second);
void func_000FE4E0(int kind, int value, int flag);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc9c];
    int value_c9c;
    char unknown_ca0[0x31c];
    int value_fbc;
    char unknown_fc0[0x90];
    unsigned int tricks;

    void func_0009BB40();
};

// Counts a trick at 0x1050; when func_0004EB80(1, 1) allows it and 0xc9c is clear, the 30th, 50th, 100th and 200th
// trick each send their kind (0x19 to 0x1c) with the value at 0xfbc to func_000FE4E0.
void Object_000A1C50::func_0009BB40()
{
    tricks++;
    if (func_0004EB80(1, 1) && !value_c9c) {
        switch (tricks) {
        case 30:
            func_000FE4E0(0x19, value_fbc, 0);
            break;
        case 50:
            func_000FE4E0(0x1a, value_fbc, 0);
            break;
        case 100:
            func_000FE4E0(0x1b, value_fbc, 0);
            break;
        case 200:
            func_000FE4E0(0x1c, value_fbc, 0);
            break;
        }
    }
}
