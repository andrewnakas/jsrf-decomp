struct Object_000E5650 {
    char unknown_00[8];
    int state;
    int unknown_0c;
    int timer;
    char unknown_14[0x20];
    int mode;

    void func_000E5650();
};

void Object_000E5650::func_000E5650()
{
    if (mode == 2) {
        state = 10;
        timer = 0;
    }
}
