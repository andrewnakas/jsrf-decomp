extern unsigned long data_0019DED8;
// The texture-stage state table: 4 stages of 32 entries, just below the render-state table at 0x19E0E0.
extern unsigned long data_0019DEE0[4][32];
extern unsigned long data_0019E0E0[];
extern unsigned long data_00264EDC;
void __stdcall func_0018DED0(unsigned long first, void **second);
void __stdcall func_0018DF10(unsigned long first, void *second);
unsigned long __stdcall func_00192990(void *object);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150FE0(float value);  // slot 106

    char unknown_04[0x4C];
    float value_50;
};

// Gives stage 3 what 0x18DED0 returns for stage 0 and stage 0's states 12, 14, 15, 16, 18 and 19, marks the flags
// they need, sets render states 108 and 109 to 1 and 106 to the value, and keeps in render state 112 the square
// of the global at 0x264EDC divided by the float at 0x50.
long __stdcall Object_001E0F00::func_00150FE0(float value)
{
    void *object = 0;
    float scale;
    float square;

    func_0018DED0(0, &object);
    func_0018DF10(3, object);
    func_00192990(object);
    data_0019DEE0[3][12] = data_0019DEE0[0][12];
    data_0019DEE0[3][14] = data_0019DEE0[0][14];
    data_0019DEE0[3][15] = data_0019DEE0[0][15];
    data_0019DEE0[3][16] = data_0019DEE0[0][16];
    data_0019DEE0[3][18] = data_0019DEE0[0][18];
    data_0019DEE0[3][19] = data_0019DEE0[0][19];
    data_0019DED8 |= (data_0019DEE0[3][12] < 25 ? 0x800 : 0x480F) | 0x900;
    data_0019E0E0[108] = 1;
    scale = (float)data_00264EDC / value_50;
    square = scale * scale;
    data_0019E0E0[109] = 1;
    *(float *)&data_0019E0E0[106] = value;
    data_0019DED8 |= 0x100;
    data_0019E0E0[112] = *(unsigned long *)&square;
    return 0;
}
