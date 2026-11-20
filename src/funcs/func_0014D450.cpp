/* sym: ?func_0014D490@Object_001E11B8@@UAGJPBXPAPAX@Z = 0x0014D450 */
extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E13B0;

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014D4A0();  // slot 1
};

// The class whose table is at 0x1E11B8 (created by 0x14D8E0).
struct Object_001E11B8 : Object_001E10E8 {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0, at 0x14D450
};

// QueryInterface: only the interface id at 0x1E13B0.
long __stdcall Object_001E11B8::func_0014D490(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E13B0, sizeof(Guid)) == 0) {
        *object = this;
        func_0014D4A0();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
