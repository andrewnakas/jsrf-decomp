extern void *data_0022E780[16];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    int func_00154970(void *resource);
};

// Whether the resource is one of the sixteen in the table at 0x22E780.
int Object_001E0F00::func_00154970(void *resource)
{
    for (unsigned int i = 0; i < 16; i++) {
        if (data_0022E780[i] == resource)
            return 1;
    }
    return 0;
}
