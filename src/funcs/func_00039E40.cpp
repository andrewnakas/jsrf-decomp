struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_04[0xd4];
    unsigned int bits_d8[8];

    int func_00039E40(unsigned int index);
};

int Object_00039BE0::func_00039E40(unsigned int index)
{
    if (index < 0x100 && (bits_d8[index >> 5] & (1 << (index & 0x1f)))) {
        return 1;
    }
    return 0;
}
