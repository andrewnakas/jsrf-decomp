extern unsigned long data_0019DED8;
// The texture-stage state table: 4 stages of 32 entries, just below the render-state table at 0x19E0E0.
extern unsigned long data_0019DEE0[4][32];
// The dirty flags of texture-stage states 12 to 21.
extern const unsigned long data_001C4160[22];
void __stdcall func_0018F060(unsigned long first, unsigned long second);
void __stdcall func_0018F1F0(unsigned long stage, unsigned long value);
void __stdcall func_0018F230(unsigned long stage, unsigned long value);
void __stdcall func_0018F180(unsigned long stage, int type, unsigned long value);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001502F0(unsigned long stage, int type, unsigned long value);  // slot 112
};

// Sets texture-stage state type of the stage. Types 0 to 21 are kept in the stage's table and mark dirty flags
// (the stage's bit below 12; for 12, 0x800 if the value is below 25, else 0x480F; above it, the table at
// 0x1C4160); 28, 29 and 30 go to func_0018F060, func_0018F1F0 and func_0018F230, and 22 to 27 to func_0018F180.
long __stdcall Object_001E0F00::func_001502F0(unsigned long stage, int type, unsigned long value)
{
    if (type < 12) {
        data_0019DED8 |= 1 << stage;
        data_0019DEE0[stage][type] = value;
    } else if (type == 12) {
        data_0019DED8 |= value < 25 ? 0x800 : 0x480F;
        data_0019DEE0[stage][12] = value;
    } else if (type < 22) {
        data_0019DED8 |= data_001C4160[type];
        data_0019DEE0[stage][type] = value;
    } else if (type == 28) {
        func_0018F060(stage, value);
    } else if (type == 29) {
        func_0018F1F0(stage, value);
    } else if (type == 30) {
        func_0018F230(stage, value);
    } else if (type <= 27) {
        func_0018F180(stage, type, value);
    }
    return 0;
}
