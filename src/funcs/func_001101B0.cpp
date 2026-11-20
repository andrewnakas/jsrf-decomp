struct Object_001101B0 {
    char unknown_000[0x210];
    int state;

    int func_001101B0();
};

// Whether the word at +0x210 is 3.
int Object_001101B0::func_001101B0()
{
    return state == 3;
}
