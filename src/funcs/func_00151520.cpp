/* const: 0x40304 */
/* const: 0x40344 */
/* const: 0x40348 */
/* const: 0x4035C */
/* const: 0x40378 */
/* const: 0x40368 */
/* const: 0x40364 */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
extern unsigned long data_0019E0E0[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00151520();  // slot 103
};

// Sends 1, 0, 1, 0, 0x1E01, 1 and 0x207 as methods 0x40304, 0x40344, 0x40348, 0x4035C, 0x40378, 0x40368 and
// 0x40364 (render states 59, 62, 63, 64, 69, 71 and 70).
long __stdcall Object_001E0F00::func_00151520()
{
    func_0018E930(0x40304, 1);
    data_0019E0E0[59] = 1;
    func_0018E930(0x40344, 0);
    data_0019E0E0[62] = 0;
    func_0018E930(0x40348, 1);
    data_0019E0E0[63] = 1;
    func_0018E930(0x4035C, 0);
    data_0019E0E0[64] = 0;
    func_0018E930(0x40378, 0x1E01);
    data_0019E0E0[69] = 0x1E01;
    func_0018E930(0x40368, 1);
    data_0019E0E0[71] = 1;
    func_0018E930(0x40364, 0x207);
    data_0019E0E0[70] = 0x207;
    return 0;
}
