/* const: 0x40344 */
/* const: 0x40348 */
/* const: 0x4035C */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
void __stdcall func_0018F760(unsigned long value);
extern unsigned long data_0019E0E0[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00151670();  // slot 102
};

// Sends 0x302, 0x303 and 1 as methods 0x40344, 0x40348 and 0x4035C (render states 62, 63 and 64), then calls
// func_0018F760 with 0.
long __stdcall Object_001E0F00::func_00151670()
{
    func_0018E930(0x40344, 0x302);
    data_0019E0E0[62] = 0x302;
    func_0018E930(0x40348, 0x303);
    data_0019E0E0[63] = 0x303;
    func_0018E930(0x4035C, 1);
    data_0019E0E0[64] = 1;
    func_0018F760(0);
    return 0;
}
