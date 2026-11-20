extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E13E0;
extern const Guid data_001E4C94;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014CF00();  // slot 1
};

// QueryInterface: the interface ids at 0x1E13E0 and 0x1E4C94.
long __stdcall Object_001E0F00::func_0014CF20(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E13E0, sizeof(Guid)) == 0 || memcmp(iid, &data_001E4C94, sizeof(Guid)) == 0) {
        *object = this;
        func_0014CF00();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
