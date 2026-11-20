extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

struct Unknown;

extern const Guid data_001E4C94;
extern const Guid data_001E3D10;
extern const Guid data_001E3CF0;

long __stdcall func_00172D30(Unknown *outer, void **object);
long __stdcall func_00172DD0(Unknown *outer, void **object);

// Equal when they are the same object or have the same sixteen bytes (the out-of-line copy is at 0x15FA30).
inline bool operator==(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}

// The class factory of MRIFFFile (table 0x1E3CD8, right after the "MUSASHI.MRIFFFile.1" strings).
struct MRIFFFileFactory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00172C90(Unknown *outer, const Guid &id, void **object);
};

// CreateInstance (slot 3): IID_IUnknown (0x1E4C94) and the interface 0x1E3D10 create the class with table 0x1E3D30
// (func_00172D30), the interface 0x1E3CF0 the class with table 0x1E3D88 (func_00172DD0); anything else fails with
// E_NOINTERFACE.
long __stdcall MRIFFFileFactory::func_00172C90(Unknown *outer, const Guid &id, void **object)
{
    if (id == data_001E4C94 || id == data_001E3D10)
        return func_00172D30(outer, object);
    if (id == data_001E3CF0)
        return func_00172DD0(outer, object);
    *object = 0;
    return 0x80004002;
}
