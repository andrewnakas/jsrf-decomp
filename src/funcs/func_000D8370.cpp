struct Object_000D8370 {
    char unknown_00[8];
    int state;
    char unknown_0c[0xd4];
    int mode;

    void func_000D8370();
};

void Object_000D8370::func_000D8370()
{
    if (mode != 10) {
        state = 5;
    }
}
