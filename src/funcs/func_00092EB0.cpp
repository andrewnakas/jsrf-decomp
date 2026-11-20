struct Object_00092EB0 {
    char unknown_000[0xe58];
    int phase;

    int func_00092EB0(int index, int unused);
};

extern int (Object_00092EB0::*data_0020E11C[])();

// Sets the phase and runs the handler the table holds for the index; the same shape as func_00092E90.
int Object_00092EB0::func_00092EB0(int index, int)
{
    phase = 3;
    return (this->*data_0020E11C[index])();
}
