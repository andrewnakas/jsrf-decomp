struct Object_0007F4E0 {
    char unknown_000[0xe50];
    unsigned int state;

    int func_0007F4E0();
};

// Says whether the state at +0xe50 is 0x18 or 0x19.
int Object_0007F4E0::func_0007F4E0()
{
    if (state >= 0x18 && state <= 0x19) {
        return 1;
    }
    return 0;
}
