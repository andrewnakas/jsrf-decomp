extern unsigned char data_00264F50[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual int __stdcall func_001548E0(int index);  // slot 13
};

// Whether entry index of the byte table at 0x264F50 is set.
int __stdcall Object_001E0F00::func_001548E0(int index)
{
    return data_00264F50[index] != 0;
}
