extern unsigned long data_0019DED8;
extern unsigned long data_0019E0E0[];
extern float data_00264D38[3];
void __fastcall func_001869E0(float *rgb, unsigned long color);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual void __stdcall func_0014FDB0(unsigned long color);  // slot 22
};

// Keeps the colour in entry 105 of the render-state table, marks flag 0x1000 dirty and keeps it as three floats at 0x264D38.
void __stdcall Object_001E0F00::func_0014FDB0(unsigned long color)
{
    data_0019DED8 |= 0x1000;
    data_0019E0E0[105] = color;
    func_001869E0(data_00264D38, color);
}
