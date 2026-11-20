struct Object_000265A0 {
    char unknown_0000[0x1604];
    int unknown_1604;
    char unknown_1608[0x10];
    int unknown_1618;

    int func_00034810(int unused);
};

// Handler in the table at 0x1EC068 (called with one argument at 0x253b5): resets the fields at +0x1604 and +0x1618.
int Object_000265A0::func_00034810(int)
{
    unknown_1604 = 0;
    unknown_1618 = 1;
    return 1;
}
