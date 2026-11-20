struct Object_000265A0 {
    char unknown_0000[0x738];
    int unknown_0738;
    int unknown_073c;

    int func_00030D00(int unused);
};

// Handler in the table at 0x1EC068 (called with one argument at 0x253b5): clears the fields at +0x738 and +0x73c.
int Object_000265A0::func_00030D00(int)
{
    unknown_0738 = 0;
    unknown_073c = 0;
    return 1;
}
