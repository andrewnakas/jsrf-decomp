struct Object_000265A0 {
    char unknown_0000[0x270];
    int unknown_0270;

    int func_00031480(int unused);
};

// Says whether the field at +0x270 is zero. The table caller (0x256e5) passes one argument to every handler.
int Object_000265A0::func_00031480(int)
{
    return unknown_0270 == 0;
}
