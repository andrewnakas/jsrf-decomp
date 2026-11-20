/* const: 0x40344 */
/* const: 0x40348 */
/* const: 0x4035C */
/* const: 0x40378 */
/* const: 0x40364 */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
extern unsigned long data_0019E0E0[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001515D0(unsigned long mode);  // slot 104
};

// Mode 1 or 2: sends 0x302, 0x303, 1, 0x1E00 and 0x203 (mode 1) or 0x204 as methods 0x40344, 0x40348, 0x4035C,
// 0x40378 and 0x40364 and keeps them in render states 62, 63, 64, 69 and 70. Other modes: 0x80070057 (E_INVALIDARG).
long __stdcall Object_001E0F00::func_001515D0(unsigned long mode)
{
    unsigned long value;

    switch (mode) {
    case 1:
        value = 0x203;
        break;
    case 2:
        value = 0x204;
        break;
    default:
        return 0x80070057;
    }
    func_0018E930(0x40344, 0x302);
    data_0019E0E0[62] = 0x302;
    func_0018E930(0x40348, 0x303);
    data_0019E0E0[63] = 0x303;
    func_0018E930(0x4035C, 1);
    data_0019E0E0[64] = 1;
    func_0018E930(0x40378, 0x1E00);
    data_0019E0E0[69] = 0x1E00;
    func_0018E930(0x40364, value);
    data_0019E0E0[70] = value;
    return 0;
}
