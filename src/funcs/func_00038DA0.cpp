struct Object_000265A0 {
    char unknown_0000[0x1878];
    int unknown_1878;
    int unknown_187c;
    int unknown_1880;

    int func_00038DA0(int value);
};

// Handler in the table at 0x1EC068 (called with one argument at 0x253b5): stores its argument at +0x187c and clears the fields beside it.
int Object_000265A0::func_00038DA0(int value)
{
    unknown_1880 = 0;
    unknown_187c = value;
    unknown_1878 = 0;
    return 1;
}
