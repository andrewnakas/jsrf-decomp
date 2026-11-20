struct Object_000A1C50 {
    char unknown_000[0xe50];
    unsigned int state;

    int func_0007F500();
};

// Says whether the state at +0xe50 lies outside 0x14 to 0x1a.
int Object_000A1C50::func_0007F500()
{
    if (state >= 0x14 && state <= 0x1a) {
        return 0;
    }
    return 1;
}
