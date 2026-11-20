struct Object_000265A0 {
    char unknown_0000[0x1900];
    void *unknown_1900;
    char unknown_1904[0x8];
    int unknown_190c;

    void *func_000263A0(int unused1, int unused2, int unused3);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the pointer at +0x1900 while the field at +0x190c is set.
void *Object_000265A0::func_000263A0(int, int, int)
{
    if (unknown_190c) {
        return unknown_1900;
    }
    return 0;
}
