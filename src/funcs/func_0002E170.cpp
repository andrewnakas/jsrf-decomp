struct Object_000265A0 {
    char unknown_0000[0x184c];
    int unknown_184c;
    int unknown_1850;

    int func_0002E170(int unused);
};

// Handler in the table at 0x1EC068 (called with one argument at 0x253b5): clears the fields at +0x184c and +0x1850.
int Object_000265A0::func_0002E170(int)
{
    unknown_1850 = 0;
    unknown_184c = 0;
    return 1;
}
