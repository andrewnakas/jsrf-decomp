struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_0004[0x14];
    unsigned int bits_18[0x10];
    unsigned int bits_58[0x10];
    unsigned int bits_98[0x10];
    char unknown_00d8[0x693c];
    unsigned int bits_6a14[0x10];

    int func_00039B50(int value);
};

// Says whether one bit of one of four 512-bit sets has the state the value asks for. The value packs the set
// (bits 0-2), the bit number (bits 3-18) and the state (bit 19).
int Object_00039BE0::func_00039B50(int value)
{
    unsigned int type = value & 7;
    unsigned int index = ((unsigned int)value >> 3) & 0xffff;
    unsigned int state = ((unsigned int)value >> 19) & 1;
    if (type <= 3 && index < 0x200) {
        unsigned int *bits;
        switch (type) {
        case 0:
            bits = bits_6a14;
            break;
        case 1:
            bits = bits_18;
            break;
        case 2:
            bits = bits_58;
            break;
        case 3:
            bits = bits_98;
            break;
        }
        return ((bits[index >> 5] >> (index & 0x1f)) & 1) == state;
    }
    return 0;
}
