// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual unsigned long __stdcall func_0014CF00();  // slot 1

    char unknown_04[0xdc];
    unsigned long references;
};

// AddRef: counts one more reference and returns the new count.
unsigned long __stdcall Object_001E0F00::func_0014CF00()
{
    return ++references;
}
