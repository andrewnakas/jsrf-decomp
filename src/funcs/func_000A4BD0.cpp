struct Object_000A4BD0 {
    char unknown_000[0x228];
    int value_228;
    char unknown_22c[8];
    int value_234;
    int latched;

    void func_000A4BD0();
};

// The first time only: copies the field at 0x228 to 0x234 and sets the latch at 0x238.
void Object_000A4BD0::func_000A4BD0()
{
    if (!latched) {
        value_234 = value_228;
        latched = 1;
    }
}
