struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_04[0xd4];
    unsigned int bits_d8[8];
    unsigned int bits_f8[8];
    unsigned int bits_118[8];

    void func_00039E80(unsigned int index);
};

void Object_00039BE0::func_00039E80(unsigned int index)
{
    if (index < 0x100) {
        bits_f8[index >> 5] |= 1 << (index & 0x1f);
        bits_118[index >> 5] |= 1 << (index & 0x1f);
    }
}
