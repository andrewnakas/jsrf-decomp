struct Game {
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

// -1 when value 0x1b6 of the game is 3, else 0.
int func_001354A0()
{
    if (data_0022FCE0->func_000127E0(0x1b6) == 3) {
        return -1;
    }
    return 0;
}
