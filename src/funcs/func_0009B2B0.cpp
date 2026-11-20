struct Object_000A0610 {
    char unknown_000[0xf14];
    int active;

    void func_000A0610(int mode);
    void func_0009B2B0();
};

void Object_000A0610::func_0009B2B0()
{
    if (active) {
        func_000A0610(1);
    }
}
