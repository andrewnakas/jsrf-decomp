struct Object_000C7CD0 {
    char unknown_000[0xbc];
    int state;
    char unknown_0c0[0x2c];
    int timer;
    char unknown_x[0xd4];
    int mode;

    void func_000C7CD0();
};

void Object_000C7CD0::func_000C7CD0()
{
    if (mode == 2) {
        state = 12;
        timer = 0;
    }
}
