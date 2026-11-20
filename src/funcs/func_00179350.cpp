extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E4C94;
extern const Guid data_001E4C84;

// Equal when they are the same object or have the same sixteen bytes (the out-of-line copy is at 0x15FA30).
inline bool operator==(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// The class factory of MGameInput8 (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings). All eight MUSASHI
// class factories hold this function in slot 0.
struct MGameInput8Factory {
    virtual long __stdcall func_00179350(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();

    Unknown *outer;
};

// QueryInterface (slot 0): IID_IUnknown (0x1E4C94) and IID_IClassFactory (0x1E4C84) give the object itself, with a
// reference (slot 1); anything else is asked of the controlling object at +4, or fails with E_NOINTERFACE.
long __stdcall MGameInput8Factory::func_00179350(const Guid &id, void **object)
{
    long result;
    if (id == data_001E4C94 || id == data_001E4C84) {
        *object = this;
        slot1();
        result = 0;
    } else if (outer) {
        return outer->slot0(id, object);
    } else {
        *object = 0;
        result = 0x80004002;
    }
    return result;
}
