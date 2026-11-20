extern unsigned long data_0019E0E0[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual int __stdcall func_001507C0(int index, unsigned long *value);  // slot 63
};

// Reads entry index of the render-state table at 0x19E0E0.
int __stdcall Object_001E0F00::func_001507C0(int index, unsigned long *value)
{
    *value = data_0019E0E0[index];
    return 1;
}
