struct Object_00039BE0 {
    char unknown_0000[0x34cc];
    unsigned int bits_34cc[16];

    int func_0003A8C0(unsigned int index);
};

// Whether bit `index` of the bit set at +0x34cc (512 bits) is set.
int Object_00039BE0::func_0003A8C0(unsigned int index)
{
    if (index < 0x200 && (bits_34cc[index >> 5] & (1 << (index & 0x1f)))) {
        return 1;
    }
    return 0;
}
