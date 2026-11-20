extern "C" void *memcpy(void *destination, const void *source, unsigned int size);

// The system library's heap functions (the shapes of Win32's GetProcessHeap, HeapAlloc and HeapFree).
void *__stdcall func_0014A838();
void *__stdcall func_001497DC(void *heap, unsigned long flags, unsigned long size);
int __stdcall func_0014A821(void *heap, unsigned long flags, void *memory);

struct Guid;

// MemStream's first interface: the table at 0x1E3EA8.
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MemStream's second interface, at +4: the table at 0x1E3E98.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MemStream, a stream over a block of memory (two interfaces, like MGameSound8).
struct MemStream : FirstInterface, SecondInterface {
    virtual long __stdcall func_001751B0();

    void *outer;
    long references;
    void *data;
    char unknown_14[4];
    __int64 length;
    unsigned __int64 capacity;
    __int64 position;
    int growable;
    int mode;
    unsigned long setting4;
    unsigned long setting40;
    unsigned __int64 setting8;
    unsigned __int64 setting10;
    unsigned __int64 setting1;
    unsigned __int64 setting2;
    unsigned char setting20;
    unsigned long setting80;
};

// Slot 11: when the capacity is below the length and the stream may change its block (bit 1 of +0x30), moves the
// data into a block of exactly the capacity and makes that the length. E_OUTOFMEMORY when the allocation fails,
// 0x800401F0 (not initialised) before slot 3.
long __stdcall MemStream::func_001751B0()
{
    if (mode) {
        if (capacity < length && (growable & 1)) {
            void *block = func_001497DC(func_0014A838(), 0, (unsigned long)capacity);
            if (!block)
                return 0x8007000E;
            memcpy(block, data, (unsigned long)capacity);
            if (data) {
                func_0014A821(func_0014A838(), 0, data);
                data = 0;
            }
            length = capacity;
            data = block;
        }
        return 0;
    }
    return 0x800401F0;
}
