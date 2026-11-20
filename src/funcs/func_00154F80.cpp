extern void **data_002650E4;
extern unsigned int data_002650E8;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    long func_00154F80(void *resource);
};

// Takes the resource off the device's list at 0x2650E4: E_NOINTERFACE when it is not there, 1 without a list.
long Object_001E0F00::func_00154F80(void *resource)
{
    if (data_002650E8) {
        for (unsigned int i = 0; i < data_002650E8; i++) {
            if (data_002650E4[i] == resource) {
                data_002650E4[i] = 0;
                return 0;
            }
        }
        return 0x80004002;
    }
    return 1;
}
