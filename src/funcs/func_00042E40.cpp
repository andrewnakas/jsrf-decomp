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

// Releases the handle (slot 5) and the interface (slot 2).
void Object_00042CC0::func_00042E40()
{
    if (buffer) {
        if (handle) {
            buffer->slot5(handle);
            handle = 0;
        }
        buffer->slot2();
        buffer = 0;
    }
}
