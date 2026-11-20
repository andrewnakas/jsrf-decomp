extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E1718;

// A class whose table is at 0x1E1610 (11 slots; Release 0x159420, created by 0x159450).
struct Object_001E1610 {
    virtual long __stdcall func_00159180(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_00159170();  // slot 1
};

// QueryInterface: only the interface id at 0x1E1718.
long __stdcall Object_001E1610::func_00159180(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E1718, sizeof(Guid)) == 0) {
        *object = this;
        func_00159170();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
