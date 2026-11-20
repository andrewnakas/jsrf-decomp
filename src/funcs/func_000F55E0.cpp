struct Object_000F55E0 {
    char unknown_000[0xbc];
    int state;
    char unknown_0c0[0x18];
    int timer;
    char unknown_x[0x94];
    int mode;

    void func_000F55E0();
};

void Object_000F55E0::func_000F55E0()
{
    if (mode == 2) {
        state = 9;
        timer = 0;
    }
}
