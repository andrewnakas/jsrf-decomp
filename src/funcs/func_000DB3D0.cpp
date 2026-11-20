struct Object_000DB0F0 {
    char unknown_00[0x44];
    int state;

    void func_000DB0F0();
    void func_000DB3D0();
};

void Object_000DB0F0::func_000DB3D0()
{
    if (state != 2) {
        func_000DB0F0();
    }
}
