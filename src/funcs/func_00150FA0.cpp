void __stdcall func_0018ED20(unsigned long value);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150FA0(unsigned long value);  // slot 105
};

long __stdcall Object_001E0F00::func_00150FA0(unsigned long value)
{
    func_0018ED20(value);
    return 0;
}
