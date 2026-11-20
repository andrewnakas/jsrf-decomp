struct Object_000265A0 {
    char unknown_0000[0x1588];
    int unknown_1588;

    int func_0002F5F0(int unused);
};

// Says whether the field at +0x1588 is set.
int Object_000265A0::func_0002F5F0(int)
{
    return unknown_1588 != 0;
}
