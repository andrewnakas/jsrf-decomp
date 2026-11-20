struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_04[0xd4];
    unsigned int bits_d8[8];
    unsigned int bits_f8[8];

    int func_00039EF0(unsigned int index);
};

// Whether bit `index` is set in the first bit set (+0xd8) and clear in the second (+0xf8).
int Object_00039BE0::func_00039EF0(unsigned int index)
{
    if (index < 0x100) {
        unsigned int mask = 1 << (index & 0x1f);
        if (mask & ~(bits_f8[index >> 5] & mask) & bits_d8[index >> 5]) {
            return 1;
        }
    }
    return 0;
}
