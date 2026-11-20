extern unsigned long data_0019DED8;
// The texture-stage state table: 4 stages of 32 entries, just below the render-state table at 0x19E0E0.
extern unsigned long data_0019DEE0[4][32];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150280(unsigned long stage, int enable);  // slot 88
};

// Keeps 2 (enable) or 0 in entry 5 of the stage's texture-stage states and marks the stage dirty.
long __stdcall Object_001E0F00::func_00150280(unsigned long stage, int enable)
{
    data_0019DED8 |= 1 << stage;
    data_0019DEE0[stage][5] = enable ? 2 : 0;
    return 0;
}
