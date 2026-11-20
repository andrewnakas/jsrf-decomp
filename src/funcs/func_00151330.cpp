/* const: 0x40344 */
/* const: 0x40348 */
/* const: 0x40378 */
/* const: 0x40364 */
/* const: 0x40368 */
/* const: 0x40354 */
/* const: 0x4035c */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
void __stdcall func_0018EBD0(unsigned long value);
void __stdcall func_0018F760(unsigned long value);
void __stdcall func_00190490(unsigned long value);
void __stdcall func_00199600(int index, float first, float second);
void __stdcall func_00199640(int index, float first, float second, float third, float fourth);
void __stdcall func_001996A0(int kind);
void __stdcall func_001996E0();

// Direct3D's render-state table.
extern unsigned long data_0019E0E0[];
// The colour the rectangle is filled with.
extern float data_00264D54[4];

struct Rect {
    long left;
    long top;
    long right;
    long bottom;
};

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00151330(unsigned long argument1);  // slot 98

    char unknown_04[0x28];
    unsigned long value_2C;
    unsigned long width;
    unsigned long height;
};

// Slot 98: fills the rectangle argument1 points at (or the whole screen without one) with the colour at 0x264D54:
// sets the blend, depth and stencil render states it needs, draws one quad of four vertices with texture
// coordinates 0 to 1, then switches render state 64 back on.
long __stdcall Object_001E0F00::func_00151330(unsigned long argument1)
{
    const Rect *rect = (const Rect *)argument1;
    float left;
    float top;
    float right;
    float bottom;
    func_0018E930(0x40344, 0x302);
    data_0019E0E0[62] = 0x302;
    func_0018E930(0x40348, 0x303);
    data_0019E0E0[63] = 0x303;
    func_0018E930(0x40378, 0x1E00);
    data_0019E0E0[69] = 0x1E00;
    func_0018E930(0x40364, 0x203);
    data_0019E0E0[70] = 0x203;
    func_0018E930(0x40368, 1);
    data_0019E0E0[71] = 1;
    func_0018E930(0x40354, 0x203);
    data_0019E0E0[57] = 0x203;
    func_0018EBD0(0x901);
    func_00190490(0x1C4);
    func_001996A0(6);
    func_00199640(3, data_00264D54[0], data_00264D54[1], data_00264D54[2], data_00264D54[3]);
    func_00199640(4, 0.0f, 0.0f, 0.0f, 0.0f);
    if (rect) {
        left = (float)rect->left;
        top = (float)rect->top;
        right = (float)rect->right;
        bottom = (float)rect->bottom;
    } else {
        top = 0.0f;
        left = 0.0f;
        right = (float)(long)width;
        bottom = (float)(long)height;
    }
    func_00199600(9, 0.0f, 0.0f);
    func_00199640(-1, left, top, 0.5f, 0.5f);
    func_00199600(9, 1.0f, 0.0f);
    func_00199640(-1, right, top, 0.5f, 0.5f);
    func_00199600(9, 0.0f, 1.0f);
    func_00199640(-1, left, bottom, 0.5f, 0.5f);
    func_00199600(9, 1.0f, 1.0f);
    func_00199640(-1, right, bottom, 0.5f, 0.5f);
    func_001996E0();
    func_0018E930(0x4035C, 1);
    data_0019E0E0[64] = 1;
    func_0018F760(0);
    return 0;
}
