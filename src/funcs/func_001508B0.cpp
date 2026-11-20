/* const: 0x40344 */
/* const: 0x40348 */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
extern unsigned long data_0019E0E0[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001508B0(unsigned long first, unsigned long second);  // slot 74
};

// Sends the two values to the graphics processor as methods 0x40344 and 0x40348 and keeps them in entries 62
// and 63 of the render-state table.
long __stdcall Object_001E0F00::func_001508B0(unsigned long first, unsigned long second)
{
    func_0018E930(0x40344, first);
    data_0019E0E0[62] = first;
    func_0018E930(0x40348, second);
    data_0019E0E0[63] = second;
    return 0;
}
