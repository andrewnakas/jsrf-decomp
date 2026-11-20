// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc94];
    unsigned int clock;
    char unknown_c98[0x2f4];
    int value_f8c;

    void func_0009CFF0();
};

// When the field at 0xf8c is 1, it becomes 2 in the first six and the 21st to 25th of every 60 ticks of the
// counter at 0xc94.
void Object_000A1C50::func_0009CFF0()
{
    if (value_f8c == 1) {
        unsigned int tick = clock % 60;
        if (tick <= 5) {
            value_f8c = 2;
        }
        if (tick >= 21 && tick <= 25) {
            value_f8c = 2;
        }
    }
}
