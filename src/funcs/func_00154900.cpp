extern void *data_0022E740[16];
extern void *data_0022E780[16];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    void *func_00154900(unsigned int index, int second);
};

// Entry index of the table at 0x22E780 (second) or 0x22E740, else -1.
void *Object_001E0F00::func_00154900(unsigned int index, int second)
{
    if (second) {
        if (index < 16)
            return data_0022E780[index];
    } else {
        if (index < 16)
            return data_0022E740[index];
    }
    return (void *)-1;
}
