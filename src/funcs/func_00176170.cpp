/* sym: ??8@YA_NABUGuid@@0@Z = 0x0015FA30 */
extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

struct Unknown;

extern const Guid data_001E4C94;
extern const Guid data_001E3F64;
extern const Guid data_001E3F34;
extern const Guid data_001E3F54;
extern const Guid data_001E3F44;

long __stdcall func_00176280(Unknown *outer, void **object);
long __stdcall func_00176320(Unknown *outer, void **object);
long __stdcall func_001763C0(Unknown *outer, void **object);
long __stdcall func_00176460(Unknown *outer, void **object);

// Equal when they are the same object or have the same sixteen bytes. The out-of-line copy is at 0x15FA30; here
// the compiler inlined four of the five compares and called it for the fifth, so the four inline ones are written
// with this helper and the fifth calls the extern operator.
bool operator==(const Guid &a, const Guid &b);

inline bool same_guid(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}

// The class factory of MFile2 (table 0x1E3F1C, right after the "MUSASHI.MFile2.1" strings).
struct MFile2Factory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00176170(Unknown *outer, const Guid &id, void **object);
};

// CreateInstance (slot 3): IID_IUnknown (0x1E4C94) and the interface 0x1E3F64 create the class with table 0x1E3F84
// (func_00176280); 0x1E3F34 the one with table 0x1E3FB0 (func_00176320), 0x1E3F54 the one with 0x1E3FE4
// (func_001763C0), 0x1E3F44 the one with 0x1E4020 (func_00176460); anything else fails with E_NOINTERFACE. The
// compiler inlined the first four GUID compares and called the fifth (0x15FA30).
long __stdcall MFile2Factory::func_00176170(Unknown *outer, const Guid &id, void **object)
{
    if (same_guid(id, data_001E4C94) || same_guid(id, data_001E3F64))
        return func_00176280(outer, object);
    if (same_guid(id, data_001E3F34))
        return func_00176320(outer, object);
    if (same_guid(id, data_001E3F54))
        return func_001763C0(outer, object);
    if (id == data_001E3F44)
        return func_00176460(outer, object);
    *object = 0;
    return 0x80004002;
}
