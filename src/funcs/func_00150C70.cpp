struct Entry_50 {
    char unknown_00[0x50];
};

extern Entry_50 *data_00264D4C;
extern Entry_50 *data_00264D48;
void __stdcall func_0018CDA0(Entry_50 *entry);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00150C70(int index);  // slot 18
};

// Makes entry index of the 0x50-byte table at data_00264D4C the current one.
long __stdcall Object_001E0F00::func_00150C70(int index)
{
    data_00264D48 = &data_00264D4C[index];
    func_0018CDA0(&data_00264D4C[index]);
    return 0;
}
