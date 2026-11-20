extern unsigned long data_00264D64;
void __stdcall func_0018F760(unsigned long value);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00151180(unsigned long value);  // slot 97
};

// Keeps the value in the global at 0x264D64, then calls func_0018F760 with 1.
long __stdcall Object_001E0F00::func_00151180(unsigned long value)
{
    data_00264D64 = value;
    func_0018F760(1);
    return 0;
}
