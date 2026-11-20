extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E16B8;

// A class whose table is at 0x1E144C (11 slots).
struct Object_001E144C {
    virtual long __stdcall func_00157D70(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_00157CA0();  // slot 1
};

// QueryInterface: only the interface id at 0x1E16B8.
long __stdcall Object_001E144C::func_00157D70(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E16B8, sizeof(Guid)) == 0) {
        *object = this;
        func_00157CA0();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
