struct Object_000F5600 {
    char unknown_000[0xbc];
    int state;
    char unknown_0c0[0x18];
    int timer;
    char unknown_x[0x94];
    int mode;

    void func_000F5600();
};

void Object_000F5600::func_000F5600()
{
    if (mode == 2) {
        state = 7;
        timer = 0;
    }
}
