extern "C" void *memset(void *destination, int value, unsigned int size);

struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual unsigned int __stdcall slot3(int which);
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual long __stdcall slot5();
};

// The base of the classes whose tables are at 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual void __stdcall func_00158780();  // slot 7

    char unknown_04[0x100];
    Buffer *buffer;
    unsigned int stride;
};

// Slot 7: clears the whole buffer (its count 2 entries of stride bytes) between a lock (slot 4) and an unlock
// (slot 5).
void __stdcall Object_001E14D8::func_00158780()
{
    unsigned int count = buffer->slot3(2);
    void *data = 0;
    if (buffer->slot4(&data, 0) >= 0) {
        memset(data, 0, stride * count);
        buffer->slot5();
    }
}
