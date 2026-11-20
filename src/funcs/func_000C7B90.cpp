struct Object_000C7B90 {
    char unknown_000[0x90];
    unsigned int flags;
    char unknown_094[0x28];
    int state;
    char unknown_0c0[0xfc];
    int value_1bc;

    void func_000C7B90();
};

void Object_000C7B90::func_000C7B90()
{
    if (flags & 0x80000000) {
        state = 7;
        value_1bc = 5;
    }
}
