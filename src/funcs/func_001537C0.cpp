extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E1390;

// A class whose table is at 0x1E1328 (6 slots; Release 0x153850, created by 0x1539B0).
struct Object_001E1328 {
    virtual long __stdcall func_001537C0(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001537B0();  // slot 1
};

// QueryInterface: only the interface id at 0x1E1390.
long __stdcall Object_001E1328::func_001537C0(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E1390, sizeof(Guid)) == 0) {
        *object = this;
        func_001537B0();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
