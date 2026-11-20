struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Says whether object 0x12b0 is gone.
int func_0006F190()
{
    return data_0022FCE0->func_000128C0(0x12b0) == 0;
}
