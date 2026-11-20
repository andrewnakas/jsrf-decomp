extern "C" void *memset(void *destination, int value, unsigned int size);

struct Guid;
struct SoundBuffer;

// The system library's millisecond clock.
unsigned long __stdcall func_00147748();

// The class whose table is at 0x1E3C08 (30 slots, the same Release as 0x1E3B90).
struct Object_001E3C08 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual long __stdcall func_00171E00(unsigned long flags);
    virtual long __stdcall func_00170C50(void *argument);
    virtual long __stdcall func_0016FEE0(void *argument1, void *argument2);

    long __stdcall func_0016FE20(long *value);
    long __stdcall func_00171A20(unsigned long value);

    char unknown_04[0xc];
    SoundBuffer *buffer;
    char unknown_14[0xe4];
    unsigned long pending;
    char unknown_fc[8];
    long value;
    char unknown_108[0x260];
    unsigned long savedFlags;
    char unknown_36c[0xc];
    unsigned long time;
    char unknown_37c[4];
    unsigned long caps;
    char unknown_384[4];
    unsigned long block[0xc];
};

// Slot 10: starts playing with the flags (0x20 adds the flags kept at +0x368). Nothing to do while it plays already
// (bit 1 of +0x380 without 0x20). Notes the time, stops first (slot 11), passes the value at +0x104 to 0x16FE20 with
// flag 4, marks +0x380 as playing (bit 2 too with flags 0x42), runs slot 12 with flag 1, clears the 0x30 bytes at
// +0x388 and starts again through 0x171A20. 0x800401F0 (not initialised) without a buffer.
long __stdcall Object_001E3C08::func_00171E00(unsigned long flags)
{
    if (buffer) {
        if ((caps & 1) && !(caps & 0x20))
            return 0;
        if (flags & 0x20)
            flags = (savedFlags | flags) & ~0x20;
        time = func_00147748();
        func_00170C50(0);
        if (flags & 4) {
            pending |= 4;
            func_0016FE20(&value);
        }
        if (flags & 0x42)
            caps |= 3;
        else
            caps = (caps & ~2) | 1;
        if (flags & 1)
            func_0016FEE0(0, 0);
        memset(block, 0, sizeof(block));
        func_00171A20(0);
        return 0;
    }
    return 0x800401F0;
}
