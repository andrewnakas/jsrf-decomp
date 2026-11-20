struct Block_44 {
    unsigned long words[17];
};

struct Entry_50 {
    Block_44 block;
    unsigned long flag;
    char unknown_48[8];
};

extern Entry_50 *data_00264D4C;
extern unsigned int data_00264D50;
extern Block_44 data_0022E668;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150C00(int index);  // slot 17
    long func_00150BB0(unsigned int index);
    inline long ResetEntry(unsigned int index);
};

// What func_00150BB0 does; retail inlined it into the loop below.
inline long Object_001E0F00::ResetEntry(unsigned int index)
{
    if (index < data_00264D50) {
        data_00264D4C[index].block = data_0022E668;
        data_00264D4C[index].flag = 0;
        return 0;
    }
    return 0x80070057;
}

// Resets entry index of the 0x50-byte table at data_00264D4C (func_00150BB0), or every entry for -1 to the
// block at 0x22E668.
long __stdcall Object_001E0F00::func_00150C00(int index)
{
    if (index == -1) {
        for (unsigned int i = 0; i < data_00264D50; i++)
            ResetEntry(i);
        return 0;
    }
    return func_00150BB0(index);
}
