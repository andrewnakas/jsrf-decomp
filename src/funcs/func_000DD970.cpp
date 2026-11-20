struct Object_000DD970 {
    char unknown_00[8];
    int state;
    int unknown_0c;
    int timer;
    char unknown_14[0x1b4];
    int mode;

    void func_000DD970();
};

void Object_000DD970::func_000DD970()
{
    if (mode == 2) {
        state = 24;
        timer = 0;
    }
}
