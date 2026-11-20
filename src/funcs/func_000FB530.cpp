struct Object_000FB530 {
    char unknown_00[0x80];
    unsigned int flags;
    char unknown_84[0x10];
    int mode;

    void func_000FB530();
};

void Object_000FB530::func_000FB530()
{
    if (mode != 8) {
        flags |= 0x8000000;
    }
}
