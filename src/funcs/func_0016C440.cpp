struct Guid;
struct SoundBuffer;

// DirectSound's library code: 0x19F1F4 reads the buffer's positions.
long __stdcall func_0019F1F4(SoundBuffer *buffer, unsigned long *play, unsigned long *write);

// The DirectSound buffer, called through inline wrappers of the library's functions.
struct SoundBuffer {
    long position(unsigned long *play, unsigned long *write)
    {
        return func_0019F1F4(this, play, write);
    }
};

// A sound format: +8 is the bytes per second, +0x10 the size of the extra bytes after the first 0x12.
struct Format {
    unsigned short unknown_00[4];
    unsigned long bytesPerSecond;
    unsigned short unknown_0c[2];
    unsigned short extra;
};

// The class whose table is at 0x1E3B90 (30 slots; the destructor is the last).
struct Object_001E3B90 {
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
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual long __stdcall func_0016C440(unsigned __int64 *position, unsigned long flags);

    char unknown_04[0xc];
    SoundBuffer *buffer;
    char unknown_14[0x234];
    Format *format;
    char unknown_24c[0x2c];
    unsigned long start;
};

// Slot 20: the play position of the DirectSound buffer at +0x10 (0x19F1F4) past +0x278, in bytes for flag 1, otherwise
// in milliseconds by the bytes per second of the format. E_INVALIDARG for a null pointer, 0x800401F0 (not initialised)
// without the buffer.
long __stdcall Object_001E3B90::func_0016C440(unsigned __int64 *position, unsigned long flags)
{
    long result;
    if (buffer) {
        if (position) {
            *position = 0;
            unsigned long play;
            result = buffer->position(&play, 0);
            if (result >= 0) {
                if (flags & 1)
                    *position = play - start;
                else
                    *position = (__int64)(play - start) * 1000 / format->bytesPerSecond;
            }
        } else {
            result = 0x80070057;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
