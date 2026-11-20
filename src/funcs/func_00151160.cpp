extern float data_00264D54[4];
void __fastcall func_00186A30(float *rgba, unsigned long color);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00151160(unsigned long color);  // slot 96
};

// Keeps the colour as four floats at 0x264D54.
long __stdcall Object_001E0F00::func_00151160(unsigned long color)
{
    func_00186A30(data_00264D54, color);
    return 0;
}
