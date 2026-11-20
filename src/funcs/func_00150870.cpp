extern unsigned long data_0019DED8;
extern unsigned long data_0019E0E0[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150870(unsigned long value);  // slot 72
};

// Keeps the value in entry 95 of the render-state table at 0x19E0E0 and marks flags 0x1000 at 0x19DED8 dirty.
long __stdcall Object_001E0F00::func_00150870(unsigned long value)
{
    data_0019DED8 |= 0x1000;
    data_0019E0E0[95] = value;
    return 0;
}
