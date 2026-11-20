struct Object_000265A0 {
    char unknown_0000[0x1598];
    void *values[6];
    char unknown_15b0[0xc];
    int unknown_15bc;

    void *func_0002C010(int index, int unused1, int unused2);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): one of the six values at +0x1598 while the field at +0x15bc is set.
void *Object_000265A0::func_0002C010(int index, int, int)
{
    if (unknown_15bc && (unsigned int)index < 6) {
        return values[index];
    }
    return 0;
}
