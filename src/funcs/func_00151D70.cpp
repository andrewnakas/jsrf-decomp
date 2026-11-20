extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E1350;

// A class whose table is at 0x1E1270 (8 slots; Release 0x152230, created by 0x152270).
struct Object_001E1270 {
    virtual long __stdcall func_00151D70(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_00152150();  // slot 1
};

// QueryInterface: only the interface id at 0x1E1350.
long __stdcall Object_001E1270::func_00151D70(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E1350, sizeof(Guid)) == 0) {
        *object = this;
        func_00152150();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
