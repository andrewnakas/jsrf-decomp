// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014D0F0(unsigned long *value);  // slot 43

    char unknown_04[0x68];
    unsigned long value_6c;
};

// Reads the word at +0x6C; E_INVALIDARG without a destination.
long __stdcall Object_001E0F00::func_0014D0F0(unsigned long *value)
{
    if (value) {
        *value = value_6c;
        return 0;
    }
    return 0x80070057;
}
