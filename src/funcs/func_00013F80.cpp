void func_000659C0();
void __stdcall func_00145CA6(unsigned long milliseconds);

struct Game {
    char unknown_00[0x10];
    int unknown_10;
    char unknown_14[0x10];
    int stopped;

    void func_00013A80();
    int func_00013F80();
};

// The main loop: runs a frame (func_00013A80) for ever, or once stopped, func_000659C0 and a 16 ms sleep. -1 when
// the word at +0x10 is negative.
int Game::func_00013F80()
{
    if (unknown_10 >= 0) {
        for (;;) {
            if (!stopped) {
                func_00013A80();
            } else {
                func_000659C0();
                func_00145CA6(0x10);
            }
        }
    }
    return -1;
}
