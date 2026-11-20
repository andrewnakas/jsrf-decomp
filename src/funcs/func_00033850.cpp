struct Object_000265A0 {
    char unknown_0000[0x18dc];
    int unknown_18dc;
    int unknown_18e0;

    void *func_00033850(int unused1, int unused2, int unused3);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the address of the field at +0x18dc while the field at +0x18e0 is set.
void *Object_000265A0::func_00033850(int, int, int)
{
    if (unknown_18e0) {
        return &unknown_18dc;
    }
    return 0;
}
