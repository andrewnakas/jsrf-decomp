extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual long __stdcall slot5();
};

// A class whose table is at 0x1E144C (11 slots; Release 0x157DB0).
struct Object_001E144C {
    virtual long __stdcall func_00157C50();  // slot 7

    Buffer *buffer;
    unsigned int count;
};

// Locks the buffer at +4, clears 128 bytes per entry and unlocks it.
long __stdcall Object_001E144C::func_00157C50()
{
    void *data = 0;
    long result = buffer->slot4(&data, 0);
    if (result >= 0) {
        memset(data, 0, count * 128);
        result = buffer->slot5();
    }
    return result;
}
