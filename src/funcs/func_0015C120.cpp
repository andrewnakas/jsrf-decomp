/* sym: ?func_00157F00_2@Object_001E15C0@@UAGJPBXPAPAX@Z = 0x0015C120 */
extern "C" int __cdecl memcmp(const void *first, const void *second, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E1708;

// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual long __stdcall func_00157F00_2(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_00158EE0();  // slot 1
};

// The class whose table is at 0x1E15C0 (created by 0x158F00).
struct Object_001E15C0 : Object_001E1598 {
    virtual long __stdcall func_00157F00_2(const void *iid, void **object);  // slot 0, at 0x0015C120
};

// QueryInterface: only the interface id at 0x1E1708.
long __stdcall Object_001E15C0::func_00157F00_2(const void *iid, void **object)
{
    if (memcmp(iid, &data_001E1708, sizeof(Guid)) == 0) {
        *object = this;
        func_00158EE0();
        return 0;
    }
    *object = 0;
    return 0x80004002;
}
