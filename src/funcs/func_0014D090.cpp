extern unsigned long data_00264C1C;
unsigned long __stdcall func_00198F10(unsigned long flags);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014D090();  // slot 46
    void func_00154AE0();
    void func_00154C20();
    void func_00154C30();
};

long __stdcall Object_001E0F00::func_0014D090()
{
    func_00154C30();
    func_00154AE0();
    data_00264C1C = 0;
    func_00198F10(0);
    func_00154C20();
    return 0;
}
