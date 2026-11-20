struct Object_000E6E80 {
    char unknown_00[0xa0];
    unsigned int flags;

    void func_000E6E80();
    void func_000E7540();
};

void Object_000E6E80::func_000E7540()
{
    if (!(flags & 1)) {
        func_000E6E80();
    }
}
