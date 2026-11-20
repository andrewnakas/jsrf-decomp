struct Object_000D1720 {
    char unknown_00[8];
    int state;
    char unknown_0c[0x74];
    int mode;

    void func_000D1720();
};

// State 1, and the mode at 0x80 toggles between 14 and 18.
void Object_000D1720::func_000D1720()
{
    state = 1;
    mode = (mode == 14) ? 18 : 14;
}
