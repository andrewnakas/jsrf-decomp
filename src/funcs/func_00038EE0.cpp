struct Object_000265A0 {
    char unknown_0000[0x174c];
    int unknown_174c;
    char unknown_1750[0x20];
    int unknown_1770;
    char unknown_1774[8];
    int unknown_177c;

    void *func_00038EE0(int unused1, int which, int unused2);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the address of the field at +0x174c or +0x177c while the field at +0x1770 is set.
void *Object_000265A0::func_00038EE0(int, int which, int)
{
    if (unknown_1770) {
        switch (which) {
        case 0:
            return &unknown_174c;
        case 1:
            return &unknown_177c;
        }
    }
    return 0;
}
