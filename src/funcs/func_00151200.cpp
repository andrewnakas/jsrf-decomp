/* const: 0x40354 */
/* const: 0x40304 */
/* const: 0x40344 */
/* const: 0x40348 */
/* const: 0x4035C */
/* const: 0x40364 */
/* const: 0x40378 */
/* const: 0x40368 */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
void __stdcall func_0018EBD0(unsigned long mode);
extern unsigned long data_0019E0E0[];
extern unsigned long data_00264D64;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00151200();  // slot 99
};

// If the global at 0x264D64 is 1: sends 0x206 as method 0x40354 (render state 57) and calls func_0018EBD0 with
// 0x900, else with 0x901. Then sends 1, 0, 1, 0, 0x207, 0x1E02 and 1 as methods 0x40304, 0x40344, 0x40348,
// 0x4035C, 0x40364, 0x40378 and 0x40368 (render states 59, 62, 63, 64, 70, 69 and 71).
long __stdcall Object_001E0F00::func_00151200()
{
    if (data_00264D64 == 1) {
        func_0018E930(0x40354, 0x206);
        data_0019E0E0[57] = 0x206;
        func_0018EBD0(0x900);
    } else {
        func_0018EBD0(0x901);
    }
    func_0018E930(0x40304, 1);
    data_0019E0E0[59] = 1;
    func_0018E930(0x40344, 0);
    data_0019E0E0[62] = 0;
    func_0018E930(0x40348, 1);
    data_0019E0E0[63] = 1;
    func_0018E930(0x4035C, 0);
    data_0019E0E0[64] = 0;
    func_0018E930(0x40364, 0x207);
    data_0019E0E0[70] = 0x207;
    func_0018E930(0x40378, 0x1E02);
    data_0019E0E0[69] = 0x1E02;
    func_0018E930(0x40368, 1);
    data_0019E0E0[71] = 1;
    return 0;
}
