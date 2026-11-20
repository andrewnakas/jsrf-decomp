struct Object_000265A0 {
    char unknown_0000[0x1910];
    void *unknown_1910;
    char unknown_1914[0x8];
    int unknown_191c;

    void *func_000264B0(int unused1, int unused2, int unused3);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the pointer at +0x1910 while the field at +0x191c is set.
void *Object_000265A0::func_000264B0(int, int, int)
{
    if (unknown_191c) {
        return unknown_1910;
    }
    return 0;
}
