/* const: 0x40304 */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
extern unsigned long data_0019E0E0[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150890(unsigned long value);  // slot 73
};

// Sends the value to the graphics processor as method 0x40304 and keeps it in entry 59 of the render-state table.
long __stdcall Object_001E0F00::func_00150890(unsigned long value)
{
    func_0018E930(0x40304, value);
    data_0019E0E0[59] = value;
    return 0;
}
