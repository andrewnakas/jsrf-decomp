struct Object_000149B0 {
    char unknown_00[0x8];
    int unknown_08;
    char unknown_0c[0x14];
    int unknown_20;

    void func_000149F0(int value);
};

void Object_000149B0::func_000149F0(int value)
{
    unknown_08 = value;
    if (!value) {
        unknown_20 = -1;
    }
}
