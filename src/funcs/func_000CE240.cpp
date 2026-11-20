struct Object_000CE240 {
    char unknown_00[8];
    int state;
    int unknown_0c;
    int timer;
    char unknown_14[0x88];
    int mode;

    void func_000CE240();
};

void Object_000CE240::func_000CE240()
{
    if (mode == 2) {
        state = 22;
        timer = 0;
    }
}
