struct Object_000265A0 {
    char unknown_0000[0x18ac];
    int unknown_18ac;
    int unknown_18b0;

    void *func_0002D020(int unused1, int unused2, int unused3);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the address of the field at +0x18ac while the field at +0x18b0 is set.
void *Object_000265A0::func_0002D020(int, int, int)
{
    if (unknown_18b0) {
        return &unknown_18ac;
    }
    return 0;
}
