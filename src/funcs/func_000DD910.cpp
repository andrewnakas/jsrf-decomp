struct Object_000DD910 {
    char unknown_00[8];
    int state;
    int unknown_0c;
    int timer;
    char unknown_14[0x1b4];
    int mode;

    void func_000DD910();
};

void Object_000DD910::func_000DD910()
{
    if (mode == 2) {
        state = 19;
        timer = 0;
    }
}
