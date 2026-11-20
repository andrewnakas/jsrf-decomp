/* sym: ?func_00157F00@Object_001E1498@@UAGJPBXPAPAX@Z = 0x00157DE0 */
extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E1738;

// The base of the classes whose tables are at 0x1E1478, 0x1E1498 and 0x1E14B8 (created by 0x158490).
struct Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0_2();  // slot 1
};

// The class whose table is at 0x1E1498 (created by 0x158490).
struct Object_001E1498 : Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0, at 0x00157DE0
};

// QueryInterface: only the interface id at 0x1E1738.
long __stdcall Object_001E1498::func_00157F00(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E1738, sizeof(Guid)) == 0) {
        *object = this;
        func_001532F0_2();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
