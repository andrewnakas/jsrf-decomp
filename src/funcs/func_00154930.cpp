extern void *data_0022E740[16];
extern void *data_0022E780[16];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    int func_00154930(void *resource);
};

// The index of the resource in the table at 0x22E740, else in the one at 0x22E780 (from entry 1), else -1.
int Object_001E0F00::func_00154930(void *resource)
{
    unsigned int i;
    for (i = 0; i < 16; i++) {
        if (data_0022E740[i] == resource)
            return i;
    }
    for (i = 1; i < 16; i++) {
        if (data_0022E780[i] == resource)
            return i;
    }
    return -1;
}
