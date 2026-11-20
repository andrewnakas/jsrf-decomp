/* sym: ?func_00157F00_3@Object_001E17E0@@UAGJPBXPAPAX@Z = 0x0015F800 */
extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E1804;
extern const Guid data_001E4C94;

// The base of the classes whose tables are at 0x1E17BC (constructor 0x15F1C0) and 0x1E17E0 (constructor 0x15F280): keys at +0x44.
struct Object_001E17BC {
    virtual long __stdcall func_00157F00_3(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded
    virtual unsigned long __stdcall func_0015F1B0_1();  // slot 1: AddRef, folded
};

// The class whose table is at 0x1E17E0 (constructor 0x15F280).
struct Object_001E17E0 : Object_001E17BC {
    virtual long __stdcall func_00157F00_3(const void *iid, void **object);  // slot 0, at 0x15F800
};

// QueryInterface: the interface ids at 0x1E1804 and 0x1E4C94.
long __stdcall Object_001E17E0::func_00157F00_3(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E1804, sizeof(Guid)) == 0 || memcmp(iid, &data_001E4C94, sizeof(Guid)) == 0) {
        *object = this;
        func_0015F1B0_1();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
