struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_0004[0x29f8];
    unsigned int bits_29fc[8];
    unsigned int bits_2a1c[0x20];

    int func_0003A580(unsigned int index);
};

int Object_00039BE0::func_0003A580(unsigned int index)
{
    if (index < 0x400 && (bits_2a1c[index >> 5] & (1 << (index & 0x1f)))) {
        return 1;
    }
    return 0;
}
