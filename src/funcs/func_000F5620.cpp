struct Object_000F5620 {
    char unknown_00[0xbc];
    int state;
    char unknown_c0[0xa8];
    int mode;

    void func_000F5620();
};

void Object_000F5620::func_000F5620()
{
    if (mode == 12) {
        state = 18;
    }
}
