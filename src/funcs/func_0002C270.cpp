struct Object_000265A0 {
    char unknown_0000[0x1730];
    int unknown_1730;
    int unknown_1734;
    char unknown_1738[0x10];
    int unknown_1748;

    int func_0002C270(int value);
};

// Handler in the table at 0x1EC068 (called with one argument at 0x253b5): stores its argument at +0x1730 and resets the fields beside it.
int Object_000265A0::func_0002C270(int value)
{
    unknown_1734 = 0;
    unknown_1748 = 1;
    unknown_1730 = value;
    return 1;
}
