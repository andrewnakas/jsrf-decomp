struct Object_000265A0 {
    char unknown_0000[0x168c];
    int unknown_168c;
    int unknown_1690;
    char unknown_1694[0x18];
    int unknown_16ac;

    int func_00035560(int value);
};

// Handler in the table at 0x1EC068 (called with one argument at 0x253b5): stores its argument at +0x168c and resets the fields beside it.
int Object_000265A0::func_00035560(int value)
{
    unknown_1690 = 0;
    unknown_16ac = 1;
    unknown_168c = value;
    return 1;
}
