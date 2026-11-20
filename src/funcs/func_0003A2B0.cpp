struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_04[0xf4];
    unsigned int bits_f8[8];

    int func_0003A2B0(int group, int item);
};

// Whether bit `group * 28 + item` of the bit set at +0xf8 is set.
int Object_00039BE0::func_0003A2B0(int group, int item)
{
    unsigned int index = group * 0x1c + item;
    if (index < 0x100 && (bits_f8[index >> 5] & (1 << (index & 0x1f)))) {
        return 1;
    }
    return 0;
}
