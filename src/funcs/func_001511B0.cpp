/* const: 0x40368 */
/* const: 0x40378 */
/* const: 0x40364 */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
extern unsigned long data_0019E0E0[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001511B0(unsigned long first, unsigned long second, unsigned long third);  // slot 95
};

// Sends the third, first and second values to the graphics processor as methods 0x40368, 0x40378 and 0x40364 and
// keeps them in entries 71, 69 and 70 of the render-state table.
long __stdcall Object_001E0F00::func_001511B0(unsigned long first, unsigned long second, unsigned long third)
{
    func_0018E930(0x40368, third);
    data_0019E0E0[71] = third;
    func_0018E930(0x40378, first);
    data_0019E0E0[69] = first;
    func_0018E930(0x40364, second);
    data_0019E0E0[70] = second;
    return 0;
}
