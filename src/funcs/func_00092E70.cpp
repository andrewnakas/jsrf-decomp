struct Params_00092E70 {
    int value_00;
};

struct Object_00092E70 {
    char unknown_000[0x2a0];
    Params_00092E70 *params;
    char unknown_2a4[0xb7c];
    int value_e20;

    int func_00092E70(int index, int unused);
};

extern int (Object_00092E70::*data_0020E05C[])();

// Runs the handler the table data_0020E05C holds for the index, then copies the first value of the
// parameters at 0x2a0 to 0xe20; returns the handler's result. A neighbour in the table at data_0020E488,
// func_00092E40, takes the same two arguments.
int Object_00092E70::func_00092E70(int index, int)
{
    int result = (this->*data_0020E05C[index])();
    value_e20 = params->value_00;
    return result;
}
