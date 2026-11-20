struct Object_000265A0 {
    char unknown_0000[0x18c0];
    int unknown_18c0;
    int unknown_18c4;

    void *func_00033820(int unused1, int unused2, int unused3);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the address of the field at +0x18c0 while the field at +0x18c4 is set.
void *Object_000265A0::func_00033820(int, int, int)
{
    if (unknown_18c4) {
        return &unknown_18c0;
    }
    return 0;
}
