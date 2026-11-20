void __stdcall func_0018EBD0(unsigned long mode);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150440(int mode);  // slot 66
};

// Sets cull mode 0 for mode 0, 0x900 for mode 2 and 0x901 for any other.
long __stdcall Object_001E0F00::func_00150440(int mode)
{
    switch (mode) {
    case 0:
        func_0018EBD0(0);
        return 0;
    case 2:
        func_0018EBD0(0x900);
        return 0;
    default:
        func_0018EBD0(0x901);
        return 0;
    }
}
