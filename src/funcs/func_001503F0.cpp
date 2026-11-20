void __stdcall func_0018EEF0(unsigned long mode);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001503F0(int mode);  // slot 64
};

// Sets fill mode 0x1B01, 0x1B02 or 0x1B00 for modes 0, 1 and 2.
long __stdcall Object_001E0F00::func_001503F0(int mode)
{
    switch (mode) {
    case 0:
        func_0018EEF0(0x1b01);
        return 0;
    case 1:
        func_0018EEF0(0x1b02);
        return 0;
    case 2:
        func_0018EEF0(0x1b00);
        return 0;
    }
    return 0x80070057;
}
