extern void **data_002650E4;
extern unsigned int data_002650E8;
void *__stdcall func_0014A83E(unsigned long flags, unsigned long size);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    long func_00154E40(void *parameters);
};

// Allocates the device's list of 0x200 resources (func_00154F80 takes them off it); E_OUTOFMEMORY when that fails.
long Object_001E0F00::func_00154E40(void *parameters)
{
    void *list = func_0014A83E(0x40, 0x800);
    if (list) {
        data_002650E4 = (void **)list;
        data_002650E8 = 0x200;
        return 0;
    }
    return 0x8007000e;
}
