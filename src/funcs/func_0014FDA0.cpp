long __stdcall func_0018DDE0(void *first, unsigned long second);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014FDA0(unsigned long value);  // slot 115
};

long __stdcall Object_001E0F00::func_0014FDA0(unsigned long value)
{
    return func_0018DDE0(0, value);
}
