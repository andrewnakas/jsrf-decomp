struct Object_000DADD0 {
    char unknown_00[0x44];
    int state;

    void func_000DADD0();
};

void Object_000DADD0::func_000DADD0()
{
    if (state == 0) {
        state = 3;
    }
}
