struct Entry_50 {
    char unknown_00[0x50];
};

extern Entry_50 *data_00264D4C;
extern unsigned int data_00264D50;
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    void func_00150F70();
};

// Frees the 0x50-byte table at data_00264D4C (func_00145A5D with 0x8000) and forgets it.
void Object_001E0F00::func_00150F70()
{
    if (data_00264D4C) {
        func_00145A5D(data_00264D4C, 0, 0x8000);
        data_00264D4C = 0;
        data_00264D50 = 0;
    }
}
