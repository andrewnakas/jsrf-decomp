extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

struct Unknown;

extern const Guid data_001E4C94;
extern const Guid data_001E40EC;
extern const Guid data_001E40DC;

long __stdcall func_001794A0(Unknown *outer, void **object);
long __stdcall func_00179540(Unknown *outer, void **object);

// Equal when they are the same object or have the same sixteen bytes (the out-of-line copy is at 0x15FA30).
inline bool operator==(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}

// The class factory of MEvent (table 0x1E40C4, right after the "MUSASHI.MEvent.1" strings).
struct MEventFactory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00179400(Unknown *outer, const Guid &id, void **object);
};

// CreateInstance (slot 3): IID_IUnknown (0x1E4C94) and the interface 0x1E40EC create the class with table 0x1E410C
// (func_001794A0), the interface 0x1E40DC the class with table 0x1E4130 (func_00179540); anything else fails with
// E_NOINTERFACE.
long __stdcall MEventFactory::func_00179400(Unknown *outer, const Guid &id, void **object)
{
    if (id == data_001E4C94 || id == data_001E40EC)
        return func_001794A0(outer, object);
    if (id == data_001E40DC)
        return func_00179540(outer, object);
    *object = 0;
    return 0x80004002;
}
