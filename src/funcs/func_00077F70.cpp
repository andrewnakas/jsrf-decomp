struct Game {
    void func_000127C0(int id, int value);
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

// Sets or clears one of four bits of the game's word 0x1b3: 0 the top bit, 1 bit 0, 2 bit 30, 3 bit 29.
void func_00077F70(int which, int on)
{
    unsigned int flags = data_0022FCE0->func_000127E0(0x1b3);
    switch (which) {
    case 0:
        if (on) {
            flags |= 0x80000000;
        } else {
            flags &= 0x7fffffff;
        }
        break;
    case 1:
        if (on) {
            flags |= 1;
        } else {
            flags &= ~1;
        }
        break;
    case 2:
        if (on) {
            flags |= 0x40000000;
        } else {
            flags &= ~0x40000000;
        }
        break;
    case 3:
        if (on) {
            flags |= 0x20000000;
        } else {
            flags &= ~0x20000000;
        }
        break;
    }
    data_0022FCE0->func_000127C0(0x1b3, flags);
}
