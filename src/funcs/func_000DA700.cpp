struct Object_000DA3E0 {
    char unknown_00[0x44];
    int state;

    void func_000DA3E0();
    void func_000DA700();
};

void Object_000DA3E0::func_000DA700()
{
    if (state == 0) {
        func_000DA3E0();
    }
}
