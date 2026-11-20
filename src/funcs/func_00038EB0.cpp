struct Object_000265A0 {
    char unknown_0000[0x1774];
    int unknown_1774;

    int func_00038EB0(int unused);
};

// Handler in the table at 0x1EC068 (called with one argument at 0x253b5): clears the field at +0x1774.
int Object_000265A0::func_00038EB0(int)
{
    unknown_1774 = 0;
    return 1;
}
