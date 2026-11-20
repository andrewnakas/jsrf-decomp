extern unsigned long data_0019DED8;
// The texture-stage state table: 4 stages of 32 entries, just below the render-state table at 0x19E0E0.
extern unsigned long data_0019DEE0[4][32];
extern unsigned long data_0019E0E0[];
void __stdcall func_0018DF10(unsigned long first, void *second);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001510D0();  // slot 107
};

// Clears what 0x18DF10 keeps for stage 3, sets entries 12 and 16 of stage 3's texture-stage states to 1, marks
// flags 0x900 dirty, and sets entry 106 of the render-state table to 1.0 and entries 108 and 109 to 0.
long __stdcall Object_001E0F00::func_001510D0()
{
    func_0018DF10(3, 0);
    data_0019DEE0[3][12] = 1;
    data_0019DEE0[3][16] = 1;
    data_0019DED8 |= 0x900;
    *(float *)&data_0019E0E0[106] = 1.0f;
    data_0019E0E0[108] = 0;
    data_0019E0E0[109] = 0;
    return 0;
}
