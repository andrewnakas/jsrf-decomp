struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_04[0xf4];
    unsigned int bits_f8[8];
    unsigned int bits_118[8];

    void func_00039F60();
};

// Copies the 256-bit set at +0xf8 over the one at +0x118.
void Object_00039BE0::func_00039F60()
{
    bits_118[0] = bits_f8[0];
    bits_118[1] = bits_f8[1];
    bits_118[2] = bits_f8[2];
    bits_118[3] = bits_f8[3];
    bits_118[4] = bits_f8[4];
    bits_118[5] = bits_f8[5];
    bits_118[6] = bits_f8[6];
    bits_118[7] = bits_f8[7];
}
