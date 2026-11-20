struct Object_000265A0 {
    char unknown_0000[0x1810];
    int unknown_1810;
    char unknown_1814[0x38];
    int unknown_184c;

    void *func_0002E1A0(int unused1, int unused2, int unused3);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the address of the field at +0x1810 while the field at +0x184c is set.
void *Object_000265A0::func_0002E1A0(int, int, int)
{
    if (unknown_184c) {
        return &unknown_1810;
    }
    return 0;
}
