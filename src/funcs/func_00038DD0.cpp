struct Object_000265A0 {
    char unknown_0000[0x1874];
    int unknown_1874;
    int unknown_1878;

    void *func_00038DD0(int unused1, int unused2, int unused3);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the address of the field at +0x1874 while the field at +0x1878 is set.
void *Object_000265A0::func_00038DD0(int, int, int)
{
    if (unknown_1878) {
        return &unknown_1874;
    }
    return 0;
}
