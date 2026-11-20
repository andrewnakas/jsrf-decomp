extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

struct Unknown;

// DirectInput8's class id.
extern const Guid data_001E2178;

// Equal when they are the same object or have the same sixteen bytes (the out-of-line copy is at 0x15FA30).
inline bool operator==(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}

// The class factory of DirectInput8 (table 0x1E20A0, right after the "MUSASHI.DirectInput8.1" strings).
struct DirectInput8Factory {
    DirectInput8Factory()
    {
        outer = 0;
        references = 1;
    }
    virtual long __stdcall func_00179350(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_001664D0();
    virtual long __stdcall func_00166520(Unknown *outer, const Guid &id, void **object);
    virtual long __stdcall func_00166630(int lock);
    virtual ~DirectInput8Factory()
    {
    }

    Unknown *outer;
    long references;
};

// Gets DirectInput8's class factory: for its class id creates a factory, asks it for the interface and lets go of
// the creation reference. E_OUTOFMEMORY when the allocation fails, CLASS_E_CLASSNOTAVAILABLE for any other class.
long __stdcall func_00166660(const Guid &classId, const Guid &id, void **object)
{
    if (classId == data_001E2178) {
        DirectInput8Factory *factory = new DirectInput8Factory;
        if (factory) {
            long result = factory->func_00179350(id, object);
            factory->func_001664D0();
            return result;
        }
        return 0x8007000E;
    }
    return 0x80040111;
}
