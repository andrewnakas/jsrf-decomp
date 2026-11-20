extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E4C94;
extern const Guid data_001E41B8;

// Equal when they are the same object or have the same sixteen bytes (the out-of-line copy is at 0x15FA30).
inline bool operator==(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}

// The class whose table is at 0x1E41D8: the one the MThread factory (0x1E4190) creates for IID_IUnknown and the interface 0x1E41B8.
struct Object_001E41D8 {
    virtual long __stdcall func_0017AAA0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
};

// QueryInterface (slot 0): IID_IUnknown (0x1E4C94) and the class's own interface (0x1E41B8) give the object itself,
// with a reference (slot 1); anything else fails with E_NOINTERFACE. There is no controlling object to ask.
long __stdcall Object_001E41D8::func_0017AAA0(const Guid &id, void **object)
{
    if (id == data_001E4C94 || id == data_001E41B8) {
        *object = this;
        slot1();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
