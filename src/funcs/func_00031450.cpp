struct Object_000265A0 {
    char unknown_0000[0x1f8];
    int unknown_01f8;
    char unknown_01fc[0x60];
    int unknown_025c;
    char unknown_0260[0xc];
    int unknown_026c;
    int unknown_0270;

    int func_00031450(int unused);
};

// Handler in the table at 0x1EC068 (called with one argument at 0x253b5): resets the fields at +0x1f8..+0x270.
int Object_000265A0::func_00031450(int)
{
    unknown_026c = 0;
    unknown_0270 = 1;
    unknown_01f8 = 0;
    unknown_025c = 0xc;
    return 1;
}
