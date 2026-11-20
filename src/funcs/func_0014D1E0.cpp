extern unsigned long data_00264C1C;
void __stdcall func_00190490(unsigned long value);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014D1E0(unsigned long value, unsigned long extra);  // slot 47

    char unknown_04[0x64];
    unsigned long extra_68;
};

long __stdcall Object_001E0F00::func_0014D1E0(unsigned long value, unsigned long extra)
{
    extra_68 = extra;
    data_00264C1C = value;
    func_00190490(value);
    return 0;
}
