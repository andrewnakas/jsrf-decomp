struct Object_0010FCE0 {
    char unknown_00[0x44];
    int value_44;
    int unknown_48;
    int value_4c;
    char unknown_50[0x18];
    unsigned int state;
    int timer;

    void func_0010FCE0();
};

void Object_0010FCE0::func_0010FCE0()
{
    if (state < 3) {
        timer = 0;
        value_4c = value_44;
        state = 3;
    }
}
