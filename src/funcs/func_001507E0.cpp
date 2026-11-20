/* const: 0x4037C */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
extern unsigned long data_0019E0E0[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001507E0(int smooth);  // slot 65
};

// Sends 0x1D01 (smooth) or 0x1D00 to the graphics processor as method 0x4037C and keeps it in entry 66 of the
// render-state table.
long __stdcall Object_001E0F00::func_001507E0(int smooth)
{
    unsigned long value = (smooth != 0) + 0x1D00;
    func_0018E930(0x4037C, value);
    data_0019E0E0[66] = value;
    return 0;
}
