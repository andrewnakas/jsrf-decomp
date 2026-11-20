struct Object_000E9F70 {
    char unknown_000[8];
    int state;
    char unknown_00c[0x138];
    int mode;

    int func_000E9F70();
    void func_000EA780();
};

void Object_000E9F70::func_000EA780()
{
    if (func_000E9F70()) {
        state = 3;
        mode = 2;
    }
}
