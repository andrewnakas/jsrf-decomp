struct Table_300 {
    unsigned long words[0xc0];
};

extern Table_300 *data_00264E68;
void *__stdcall func_0014A83E(unsigned long flags, unsigned long size);
void __stdcall func_0018CBC0(Table_300 *table);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    long func_00152170(void *parameters);
};

// Allocates the 0x300-byte table at data_00264E68 and fills it (func_0018CBC0); E_OUTOFMEMORY when that fails.
long Object_001E0F00::func_00152170(void *parameters)
{
    data_00264E68 = 0;
    Table_300 *table = (Table_300 *)func_0014A83E(0x40, 0x300);
    if (table) {
        func_0018CBC0(table);
        data_00264E68 = table;
        return 0;
    }
    return 0x8007000e;
}
