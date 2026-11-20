struct Object_000265A0 {
    char unknown_0000[0x1664];
    int unknown_1664;
    int unknown_1668;
    char unknown_166c[0x10];
    int unknown_167c;

    int func_00033B40(int value);
};

// Handler in the table at 0x1EC068 (called with one argument at 0x253b5): stores its argument at +0x1664 and resets the fields beside it.
int Object_000265A0::func_00033B40(int value)
{
    unknown_1668 = 0xa;
    unknown_167c = 1;
    unknown_1664 = value;
    return 1;
}
