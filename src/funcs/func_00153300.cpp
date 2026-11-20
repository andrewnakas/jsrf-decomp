extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E13D0;

// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 {
    virtual long __stdcall func_00153300(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall slot1();  // slot 1, AddRef (0x1532F0, which other tables share)
};

// QueryInterface: only the interface id at 0x1E13D0.
long __stdcall Object_001E12F8::func_00153300(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E13D0, sizeof(Guid)) == 0) {
        *object = this;
        slot1();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
