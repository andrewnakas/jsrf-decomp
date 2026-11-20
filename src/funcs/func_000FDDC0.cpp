struct Object_000FDDC0 {
    char unknown_00[0x64];
    int state;
    int timer;
    char unknown_6c[0x14];
    unsigned int flags;

    void func_000FDDC0();
};

void Object_000FDDC0::func_000FDDC0()
{
    if (state != 5) {
        flags |= 0x8000000;
        timer = 0;
        state = 4;
    }
}
