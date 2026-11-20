struct Object_000265A0 {
    char unknown_0000[0x17f4];
    int unknown_17f4;
    char unknown_17f8[0xc];
    int unknown_1804;

    void *func_000338A0(int unused1, int unused2, int unused3);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the address of the field at +0x17f4 while the field at +0x1804 is set.
void *Object_000265A0::func_000338A0(int, int, int)
{
    if (unknown_1804) {
        return &unknown_17f4;
    }
    return 0;
}
