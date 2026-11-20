extern "C" void *memset(void *, int, unsigned int);
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

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4(int first, int second, Buffer_00042CC0 **result);
};

extern Interface_00251D74 *data_00251D74;

// Creates the interface (slot 4 of 0x251D74) and its handle from the 2 MB block (its slot 3), then frees the two
// blocks and clears the words from +0xc on.
void Object_00042CC0::func_00042D20()
{
    data_00251D74->slot4(1, 0, &buffer);
    handle = buffer->slot3(0x1206, &data, 0x100);
    if (scratch) {
        operator delete(scratch);
    }
    if (data) {
        operator delete(data);
    }
    memset(&data, 0, 0x20);
}
