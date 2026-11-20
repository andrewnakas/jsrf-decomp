void __stdcall func_00190240(int enable);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014D9D0(int mode);  // slot 117
};

long __stdcall Object_001E0F00::func_0014D9D0(int mode)
{
    if (mode != 1)
        func_00190240(0);
    else
        func_00190240(1);
    return 0;
}
