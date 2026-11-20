void __stdcall func_0018F060(unsigned long first, unsigned long second);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014FE30(unsigned long first, unsigned long second);  // slot 83
};

long __stdcall Object_001E0F00::func_0014FE30(unsigned long first, unsigned long second)
{
    func_0018F060(first, second);
    return 0;
}
