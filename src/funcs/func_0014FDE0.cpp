extern int data_00264F70;
extern void **data_00264F68;
void __stdcall func_0018DF10(unsigned long first, void *second);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014FDE0(unsigned long value, int index);  // slot 81
};

// Passes entry index of the table at data_00264F68 (null for -1) to func_0018DF10; E_INVALIDARG past the end.
long __stdcall Object_001E0F00::func_0014FDE0(unsigned long value, int index)
{
    if (index < data_00264F70) {
        void *entry;
        if (index != -1)
            entry = data_00264F68[index];
        else
            entry = 0;
        func_0018DF10(value, entry);
        return 0;
    }
    return 0x80070057;
}
