extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E13A0;

// A class whose table is at 0x1E1220 (6 slots).
struct Object_001E1220 {
    virtual long __stdcall func_0014E200(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall slot1();  // slot 1, AddRef (0x14E1F0, which other tables share)
};

// QueryInterface: only the interface id at 0x1E13A0.
long __stdcall Object_001E1220::func_0014E200(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E13A0, sizeof(Guid)) == 0) {
        *object = this;
        slot1();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
