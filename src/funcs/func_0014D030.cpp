extern unsigned long data_00264C14;
extern unsigned long data_00264C1C;
void __stdcall func_00193830(unsigned long count, const void *rects, unsigned long flags, unsigned long color, float z, unsigned long stencil);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014D030(unsigned long flags);  // slot 25

    char unknown_04[0x7c];
    int stencil;
};

// Clears with the colour at 0x264C14 and depth 1; flags -1 means 0xF1, or 0xF3 when the stencil word at +0x80 is set.
long __stdcall Object_001E0F00::func_0014D030(unsigned long flags)
{
    if (flags == (unsigned long)-1) {
        flags = 0xf1;
        if (stencil)
            flags = 0xf3;
    }
    data_00264C1C = 0;
    func_00193830(0, 0, flags, data_00264C14, 1.0f, 0);
    return 0;
}
