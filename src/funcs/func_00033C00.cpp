struct Object_000265A0 {
    char unknown_0000[0x167c];
    int unknown_167c;

    int func_00033C00(int unused);
};

// Says whether the field at +0x167c is zero.
int Object_000265A0::func_00033C00(int)
{
    return unknown_167c == 0;
}
