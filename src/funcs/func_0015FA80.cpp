extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

struct Unknown;

extern const Guid data_001E4C94;
extern const Guid data_001E18C4;

long __stdcall func_0015FAF0(Unknown *outer, void **object);

// Equal when they are the same object or have the same sixteen bytes (the out-of-line copy is at 0x15FA30).
inline bool operator==(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}

// The class factory of MGameInput8 (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings).
struct MGameInput8Factory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_0015FA80(Unknown *outer, const Guid &id, void **object);
};

// CreateInstance (slot 3): for IID_IUnknown (0x1E4C94) or MGameInput8's interface (0x1E18C4) creates the object
// (func_0015FAF0); anything else fails with E_NOINTERFACE.
long __stdcall MGameInput8Factory::func_0015FA80(Unknown *outer, const Guid &id, void **object)
{
    if (id == data_001E4C94 || id == data_001E18C4)
        return func_0015FAF0(outer, object);
    *object = 0;
    return 0x80004002;
}
