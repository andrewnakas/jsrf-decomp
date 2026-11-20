extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual unsigned int __stdcall slot3(int what);
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual long __stdcall slot5();
};

// A class whose table is at 0x1E1610 (11 slots; Release 0x159420, created by 0x159450).
struct Object_001E1610 {
    virtual long __stdcall func_001590D0();  // slot 7

    Buffer *buffer;
};

// Locks the buffer at +4, clears it (the product of its slot 3 values for 3 and 2) and unlocks it.
long __stdcall Object_001E1610::func_001590D0()
{
    void *data = 0;
    long result = buffer->slot4(&data, 0);
    if (result >= 0) {
        unsigned int count = buffer->slot3(3);
        unsigned int size = buffer->slot3(2);
        memset(data, 0, count * size);
        result = buffer->slot5();
    }
    return result;
}
