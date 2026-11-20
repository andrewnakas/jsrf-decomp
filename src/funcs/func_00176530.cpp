extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

struct Unknown;

// MFile2's class id.
extern const Guid data_001E3F74;

// Equal when they are the same object or have the same sixteen bytes (the out-of-line copy is at 0x15FA30).
inline bool operator==(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}

// The class factory of MFile2 (table 0x1E3F1C, right after the "MUSASHI.MFile2.1" strings).
struct MFile2Factory {
    MFile2Factory()
    {
        outer = 0;
        references = 1;
    }
    virtual long __stdcall func_00179350(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_001664D0();
    virtual long __stdcall func_00176170(Unknown *outer, const Guid &id, void **object);
    virtual long __stdcall func_00176500(int lock);
    virtual ~MFile2Factory()
    {
    }

    Unknown *outer;
    long references;
};

// Gets MFile2's class factory: for its class id creates a factory, asks it for the interface and lets go of
// the creation reference. E_OUTOFMEMORY when the allocation fails, CLASS_E_CLASSNOTAVAILABLE for any other class.
long __stdcall func_00176530(const Guid &classId, const Guid &id, void **object)
{
    if (classId == data_001E3F74) {
        MFile2Factory *factory = new MFile2Factory;
        if (factory) {
            long result = factory->func_00179350(id, object);
            factory->func_001664D0();
            return result;
        }
        return 0x8007000E;
    }
    return 0x80040111;
}
