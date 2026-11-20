struct Params_00092E40 {
    char unknown_00[0x80];
    int value_80;
};

struct Object_00092E40 {
    char unknown_000[0x2a0];
    Params_00092E40 *params;
    char unknown_2a4[0xa30];
    int value_cd4;
    char unknown_cd8[0x188];
    int value_e60;

    int func_00092E40(int index, int unused);
};

// Clears the field at 0xe60 and takes the field at 0xcd4 from the parameters at 0x2a0; returns 0.
// Neither argument is read (`ret 8`).
int Object_00092E40::func_00092E40(int, int)
{
    value_e60 = 0;
    value_cd4 = params->value_80;
    return 0;
}
