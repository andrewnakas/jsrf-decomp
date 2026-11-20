/* const: 0x200000 */
/* const: 0x80000 */

struct Buffer_00042CC0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3(int format, void **data, int count);
    virtual long __stdcall slot4();
    virtual long __stdcall slot5(long handle);
};

// The object at 0x1F90C0: an interface from 0x251D74 (+0x4) with a handle (+0x8), and two blocks of memory.
struct Object_00042CC0 {
    int unknown_00;
    Buffer_00042CC0 *buffer;
    long handle;
    void *data;
    int unknown_10;
    int format;
    int unknown_18;
    void *scratch;
    int unknown_20;
    int unknown_24;
    int unknown_28;

    long func_00042CC0();
    void func_00042D20();
    void func_00042E40();
};

// Allocates the two blocks (2 MB and 512 KB) unless the interface is already there; E_FAIL when it is or when an
// allocation fails.
long Object_00042CC0::func_00042CC0()
{
    if (buffer || handle) {
        return 0x80004005;
    }
    data = operator new(0x200000);
    if (!data) {
        return 0x80004005;
    }
    scratch = operator new(0x80000);
    if (!scratch) {
        return 0x80004005;
    }
    format = 0x1206;
    unknown_18 = 0x20;
    unknown_24 = 0;
    return 0;
}
