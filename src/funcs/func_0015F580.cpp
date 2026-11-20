extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E1814;
extern const Guid data_001E4C94;

// A class whose table is at 0x1E1798 (9 slots, constructor 0x15F190).
struct Object_001E1798 {
    virtual long __stdcall func_0015F580(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall slot1();  // slot 1, AddRef (0x15F1B0, which other tables share)
};

// QueryInterface: the interface ids at 0x1E1814 and 0x1E4C94.
long __stdcall Object_001E1798::func_0015F580(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E1814, sizeof(Guid)) == 0 || memcmp(iid, &data_001E4C94, sizeof(Guid)) == 0) {
        *object = this;
        slot1();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
