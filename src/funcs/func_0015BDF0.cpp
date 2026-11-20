/* sym: ?func_00157F00_1@Object_001E1568@@UAGJPBXPAPAX@Z = 0x0015BDF0 */
extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E16C8;

// The base of the classes whose tables are at 0x1E14D8, 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual long __stdcall func_00157F00_1(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_00158A30();  // slot 1
};

// The class whose table is at 0x1E1568 (created by 0x158A80).
struct Object_001E1568 : Object_001E14D8 {
    virtual long __stdcall func_00157F00_1(const void *iid, void **object);  // slot 0, at 0x0015BDF0
};

// QueryInterface: only the interface id at 0x1E16C8.
long __stdcall Object_001E1568::func_00157F00_1(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E16C8, sizeof(Guid)) == 0) {
        *object = this;
        func_00158A30();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
