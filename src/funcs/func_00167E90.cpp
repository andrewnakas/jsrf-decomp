extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

struct Unknown;

extern const Guid data_001E4C94;
extern const Guid data_001E394C;

long __stdcall func_00167F00(Unknown *outer, void **object);

// Equal when they are the same object or have the same sixteen bytes (the out-of-line copy is at 0x15FA30).
inline bool operator==(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}

// The class factory of MGameSound8 (table 0x1E38E4, right after the "MUSASHI.MGameSound8.1" strings).
struct MGameSound8Factory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00167E90(Unknown *outer, const Guid &id, void **object);
};

// CreateInstance (slot 3): for IID_IUnknown (0x1E4C94) or MGameSound8's interface (0x1E394C) creates the object
// (func_00167F00); anything else fails with E_NOINTERFACE.
long __stdcall MGameSound8Factory::func_00167E90(Unknown *outer, const Guid &id, void **object)
{
    if (id == data_001E4C94 || id == data_001E394C)
        return func_00167F00(outer, object);
    *object = 0;
    return 0x80004002;
}
