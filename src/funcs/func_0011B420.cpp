struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

// Sets game value 0x1b0 to 1 or 0 by its argument.
void func_0011B420(int on)
{
    if (on) {
        data_0022FCE0->func_000127C0(0x1b0, 1);
    } else {
        data_0022FCE0->func_000127C0(0x1b0, 0);
    }
}
