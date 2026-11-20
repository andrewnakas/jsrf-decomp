extern unsigned long data_0019DED8;
// The texture-stage state table: 4 stages of 32 entries, just below the render-state table at 0x19E0E0.
extern unsigned long data_0019DEE0[4][32];
void __stdcall func_0018F060(unsigned long first, unsigned long second);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150130(unsigned long stage, unsigned long value);  // slot 84
};

// Marks flag 0x400 dirty, keeps the low half of the value in entry 21 of the stage's texture-stage states and
// passes the high half to 0x18F060.
long __stdcall Object_001E0F00::func_00150130(unsigned long stage, unsigned long value)
{
    data_0019DED8 |= 0x400;
    data_0019DEE0[stage][21] = value & 0xFFFF;
    func_0018F060(stage, value & 0xFFFF0000);
    return 0;
}
