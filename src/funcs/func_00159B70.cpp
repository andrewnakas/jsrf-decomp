extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E1748;

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159B70(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall slot1();  // slot 1, AddRef (0x14E1F0, which other tables share)
};

// QueryInterface: only the interface id at 0x1E1748.
long __stdcall Object_001E1640::func_00159B70(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E1748, sizeof(Guid)) == 0) {
        *object = this;
        slot1();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
