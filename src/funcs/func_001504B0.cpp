// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001504B0(unsigned long value);  // slot 90
};

// E_NOTIMPL. The linker folded it: it is also device slot 91, slot 7 of 0x1E12D8, slot 5 of 0x1E1568 and a
// method of several MUSASHI tables.
long __stdcall Object_001E0F00::func_001504B0(unsigned long value)
{
    return 0x80004001;
}
