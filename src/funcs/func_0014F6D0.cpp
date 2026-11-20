extern int data_00264F70;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual void __stdcall func_0014F6D0(unsigned int index);  // slot 15
    void func_0014F640(unsigned int index);
};

// Releases entry index of the tables at 0x264F68 and 0x264F6C (func_0014F640), or every entry for -1.
void __stdcall Object_001E0F00::func_0014F6D0(unsigned int index)
{
    if (index == (unsigned int)-1) {
        for (unsigned int i = 0; i < data_00264F70; i++)
            func_0014F640(i);
    } else if (index < data_00264F70) {
        func_0014F640(index);
    }
}
