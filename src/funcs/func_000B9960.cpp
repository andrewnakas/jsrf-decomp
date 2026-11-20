struct Object_000B9960 {
    char unknown_000[0x228];
    unsigned int flags;

    void func_000B8A60();
    void func_000B9270();
    void func_000B9960();
};

// Picks one of two routines by the top bit of the flags.
void Object_000B9960::func_000B9960()
{
    if (!(flags & 0x80000000)) {
        func_000B8A60();
    } else {
        func_000B9270();
    }
}
