struct Params_00092E90 {
    int value_00;
};

struct Object_000A1C50 {
    char unknown_000[0x2a0];
    Params_00092E90 *params;
    char unknown_2a4[0xb7c];
    int value_e20;
    char unknown_e24[0x34];
    int phase;

    int func_00092FC0(int index, int unused);
};

extern int (Object_000A1C50::*data_0020E3BC[])();

// Sets the phase at 0xe58 to 3 and runs the handler data_0020E3BC holds for the index, then copies the
// first value of the parameters at 0x2a0 to 0xe20; returns the handler's result. Shares the class of the
// merged func_00092E90, which does the same without the copy.
int Object_000A1C50::func_00092FC0(int index, int)
{
    phase = 3;
    int result = (this->*data_0020E3BC[index])();
    value_e20 = params->value_00;
    return result;
}
