struct Guid;
struct SoundBuffer;

// The system library's millisecond clock.
unsigned long __stdcall func_00147748();

// DirectSound's library code for the buffer object (its slots by way of the interface 0x1c bytes into it).
long __stdcall func_0019F1A0(SoundBuffer *buffer);
long __stdcall func_0019F214(SoundBuffer *buffer, unsigned long position);

// The DirectSound buffer, called through inline wrappers.
struct SoundBuffer {
    long stop()
    {
        return func_0019F1A0(this);
    }
    long rewind(unsigned long position)
    {
        return func_0019F214(this, position);
    }
};

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
    virtual void slot10();
    virtual long __stdcall func_00170C50(void *argument);

    long __stdcall func_0016FE20(long *value);
    long __stdcall func_00170A50();

    char unknown_04[0xc];
    SoundBuffer *buffer;
    char unknown_14[0xdc];
    unsigned long state;
    char unknown_f4[4];
    unsigned long pending;
    unsigned long flags;
    char unknown_100[4];
    long value;
    char unknown_108[0x268];
    unsigned long unknown_370;
    char unknown_374[4];
    unsigned long time;
    char unknown_37c[4];
    unsigned long caps;
};

// Slot 11: notes the time at +0x378; with flag 1 keeps the flags at +0xfc, clears bit 4 of +0xf8 and passes the value
// at +0x104 on to 0x16FE20. Otherwise stops the buffer (0x170A50) and, when that works, clears the state and bits 1, 2
// and 0x20 of +0x380 and stops and rewinds the DirectSound buffer; when it fails, sets bits 0x20 and 0x40 of +0x380
// in place of bits 1 and 2. 0x800401F0 (not initialised) without a buffer.
long __stdcall Object_001E3C08::func_00170C50(void *argument)
{
    if (buffer) {
        time = func_00147748();
        if ((unsigned long)argument & 1) {
            flags = (unsigned long)argument;
            pending &= ~4;
            return func_0016FE20(&value);
        }
        long result = func_00170A50();
        flags = 0;
        if (result >= 0) {
            caps &= ~0x23;
            pending = 0;
            state = 0;
            unknown_370 = 0;
            buffer->stop();
            return buffer->rewind(0);
        }
        caps = (caps & ~3) | 0x60;
        return result;
    }
    return 0x800401F0;
}
