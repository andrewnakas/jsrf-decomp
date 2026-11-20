/* const: 0x40378 */
/* const: 0x40368 */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
void __stdcall func_0018EBD0(unsigned long mode);
extern unsigned long data_0019E0E0[];
extern unsigned long data_00264D64;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001512E0();  // slot 100
};

// Sends 0x1E03 and 1 as methods 0x40378 and 0x40368 (render states 69 and 71), then calls func_0018EBD0 with
// 0x901 if the global at 0x264D64 is 1, else 0x900.
long __stdcall Object_001E0F00::func_001512E0()
{
    func_0018E930(0x40378, 0x1E03);
    data_0019E0E0[69] = 0x1E03;
    func_0018E930(0x40368, 1);
    data_0019E0E0[71] = 1;
    func_0018EBD0(data_00264D64 == 1 ? 0x901 : 0x900);
    return 0;
}
