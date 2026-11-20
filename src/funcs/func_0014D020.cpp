extern unsigned long data_00264C14;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual void __stdcall func_0014D020(unsigned long value);  // slot 24
};

// Keeps the value in the global at 0x264C14.
void __stdcall Object_001E0F00::func_0014D020(unsigned long value)
{
    data_00264C14 = value;
}
