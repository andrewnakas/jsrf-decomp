extern "C" void *memset(void *destination, int value, unsigned int size);

struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual long __stdcall slot5();
};

// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual void __stdcall func_00158E80();  // slot 7

    Buffer *buffer;
    unsigned int count;
};

// Locks the buffer (its slot 4), clears count 16-byte entries and unlocks it (slot 5).
void __stdcall Object_001E1598::func_00158E80()
{
    void *data = 0;

    if (buffer->slot4(&data, 0) >= 0) {
        memset(data, 0, count * 16);
        buffer->slot5();
    }
}
