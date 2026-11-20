extern unsigned long data_00264C18;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    long func_0014D9B0(void *parameters);
};

long Object_001E0F00::func_0014D9B0(void *parameters)
{
    data_00264C18 = 0;
    return 0;
}
