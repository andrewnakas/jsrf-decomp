struct Table_300 {
    unsigned long words[0xc0];
};

extern Table_300 *data_00264E68;
void __stdcall func_0018CB60(int kind, Table_300 *table);
int __stdcall func_0014A85B(void *handle);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    void func_001521B0();
};

// Hands the table at data_00264E68 to func_0018CB60, frees it and forgets it.
void Object_001E0F00::func_001521B0()
{
    if (data_00264E68) {
        func_0018CB60(1, data_00264E68);
        func_0014A85B(data_00264E68);
    }
    data_00264E68 = 0;
}
