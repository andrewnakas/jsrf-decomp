extern unsigned long data_0019DED8;
// The texture-stage state table: 4 stages of 32 entries, just below the render-state table at 0x19E0E0.
extern unsigned long data_0019DEE0[4][32];
extern unsigned long data_0022E654[5];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001501F0(unsigned long stage, unsigned long mode);  // slot 86
};

// Mode 0 to 4: keeps the mode's value from the table at 0x22E654 in entry 3 of the stage's texture-stage
// states and 1 (mode 0) or 2 in entry 4, and marks the stage dirty. Other modes: 0x80070057 (E_INVALIDARG).
long __stdcall Object_001E0F00::func_001501F0(unsigned long stage, unsigned long mode)
{
    if (mode < 5) {
        data_0019DEE0[stage][3] = data_0022E654[mode];
        data_0019DED8 |= 1 << stage;
        data_0019DEE0[stage][4] = (mode != 0) + 1;
        return 0;
    }
    return 0x80070057;
}
