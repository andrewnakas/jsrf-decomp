struct Object_000CE220 {
    char unknown_00[8];
    int state;
    int unknown_0c;
    int timer;
    char unknown_14[0x88];
    int mode;

    void func_000CE220();
};

void Object_000CE220::func_000CE220()
{
    if (mode == 2) {
        state = 19;
        timer = 0;
    }
}
