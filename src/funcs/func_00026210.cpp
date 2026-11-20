struct Object_000265A0 {
    char unknown_0000[0x18f4];
    int unknown_18f4;
    char unknown_18f8[0x4];
    void *unknown_18fc;

    void *func_00026210(int unused1, int unused2, int unused3);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the pointer at +0x18fc while the field at +0x18f4 is set.
void *Object_000265A0::func_00026210(int, int, int)
{
    if (unknown_18f4) {
        return unknown_18fc;
    }
    return 0;
}
