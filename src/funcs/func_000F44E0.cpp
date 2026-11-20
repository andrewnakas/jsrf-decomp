struct Object_000F44E0 {
    char unknown_00[0x44];
    unsigned int state;
    char unknown_48[0xa8];
    int target;

    void func_000F44E0();
};

void Object_000F44E0::func_000F44E0()
{
    if (state < 3 && target) {
        state = 3;
    }
}
