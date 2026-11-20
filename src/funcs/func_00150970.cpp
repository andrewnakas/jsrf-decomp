extern unsigned long data_0019DED8;
extern unsigned long data_0019E0E0[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150970(unsigned long first, unsigned long second, float third);  // slot 80
};

// Marks flag 0x2000 dirty. A non-zero third value: render state 83 is 3 and 84, 85, 86 keep the three values;
// zero: render state 83 is 0.
long __stdcall Object_001E0F00::func_00150970(unsigned long first, unsigned long second, float third)
{
    if (third != 0.0f) {
        data_0019E0E0[84] = first;
        data_0019DED8 |= 0x2000;
        data_0019E0E0[85] = second;
        data_0019E0E0[83] = 3;
        *(float *)&data_0019E0E0[86] = third;
        return 0;
    }
    data_0019DED8 |= 0x2000;
    data_0019E0E0[83] = 0;
    return 0;
}
