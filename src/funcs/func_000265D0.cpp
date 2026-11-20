struct Object_000265A0 {
    char unknown_0000[0x1628];
    int unknown_1628;
    int unknown_162c;
    char unknown_1630[0x10];
    int unknown_1640;

    int func_000265D0(int value);
};

// Handler in the table at 0x1EC068 (called with one argument at 0x253b5): stores its argument at +0x1628 and resets the fields beside it.
int Object_000265A0::func_000265D0(int value)
{
    unknown_162c = 0;
    unknown_1640 = 1;
    unknown_1628 = value;
    return 1;
}
