/* const: 0x40310 */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
extern unsigned long data_0019E0E0[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150810(unsigned long value);  // slot 67
};

// Sends the value to the graphics processor as method 0x40310 and keeps it in entry 65 of the render-state table.
long __stdcall Object_001E0F00::func_00150810(unsigned long value)
{
    func_0018E930(0x40310, value);
    data_0019E0E0[65] = value;
    return 0;
}
