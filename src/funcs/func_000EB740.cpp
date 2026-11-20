struct Object_000EB440 {
    char unknown_00[0x78];
    int state;

    void func_000EB440();
    void func_000EB740();
};

void Object_000EB440::func_000EB740()
{
    if (state == 0) {
        func_000EB440();
    }
}
