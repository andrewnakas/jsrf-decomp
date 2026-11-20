struct Object_000D1700 {
    char unknown_000[8];
    int state;
    char unknown_00c[0xf24];
    int mode;

    void func_000D1700();
};

void Object_000D1700::func_000D1700()
{
    if (mode != 7) {
        state = 11;
    }
}
