struct Object_000A1C50 {
    char unknown_000[0xe58];
    int phase;

    int func_00092E90(int index, int unused);
};

extern int (Object_000A1C50::*data_0020E0EC[])();

// Sets the phase and runs the handler the table holds for the index. func_000A07C0 calls this through
// data_00215200 with two arguments and tests the result; the handlers return 0.
int Object_000A1C50::func_00092E90(int index, int)
{
    phase = 3;
    return (this->*data_0020E0EC[index])();
}
