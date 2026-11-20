struct Object_000D8350 {
    char unknown_00[8];
    int state;
    char unknown_0c[0xd4];
    int mode;

    void func_000D8350();
};

void Object_000D8350::func_000D8350()
{
    if (mode != 8) {
        state = 6;
    }
}
