struct Game {
    void func_000127C0(int id, int value);
};

extern Game *data_0022FCE0;

struct Object_00071040 {
    char unknown_000[0xc0];
    int values[4];
    char unknown_0d0[0x430];
    int first[4];
    int second[4];

    void func_0006FDB0();
};

// Hands the four values at +0xc0 to func_000127C0 as ids 0xd to 0x10; -1 for each whose words at +0x500 and +0x510 are both clear.
void Object_00071040::func_0006FDB0()
{
    for (int i = 0; i < 4; i++) {
        if (first[i] == 0 && second[i] == 0)
            data_0022FCE0->func_000127C0(i + 0xd, -1);
        else
            data_0022FCE0->func_000127C0(i + 0xd, values[i]);
    }
}
