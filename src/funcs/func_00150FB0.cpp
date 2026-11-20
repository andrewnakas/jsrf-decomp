void __stdcall func_0018F010(int enable);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150FB0(unsigned long value);  // slot 89
};

long __stdcall Object_001E0F00::func_00150FB0(unsigned long value)
{
    func_0018F010(value != 0);
    return 0;
}
