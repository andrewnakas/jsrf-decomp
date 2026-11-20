struct Object_000265A0 {
    char unknown_0000[0x1888];
    int unknown_1888;

    void *func_0002D470(int unused1, int unused2, int unused3);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the address of the field at +0x1888.
void *Object_000265A0::func_0002D470(int, int, int)
{
    return &unknown_1888;
}
