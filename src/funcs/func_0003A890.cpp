struct Object_00039BE0 {
    char unknown_0000[0x34cc];
    unsigned int bits[0x10];

    void func_0003A890(unsigned int index);
};

// Sets one bit of the 512-bit set at +0x34cc, for an index below 0x200.
void Object_00039BE0::func_0003A890(unsigned int index)
{
    if (index < 0x200) {
        bits[index >> 5] |= 1 << (index & 0x1f);
    }
}
