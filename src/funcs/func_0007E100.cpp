struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Says whether object 0x1df3 is gone.
int func_0007E100()
{
    return data_0022FCE0->func_000128C0(0x1df3) == 0;
}
