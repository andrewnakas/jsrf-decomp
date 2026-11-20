struct Guid;

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
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual long __stdcall func_0016B9F0(unsigned __int64 *length, unsigned long flags);

    char unknown_04[0xc];
    void *ready;
    char unknown_14[0x234];
    Format *format;
    char unknown_24c[0x2c];
    unsigned long start;
    unsigned long end;
};

// Slot 28: the length between +0x278 and +0x27c, in bytes for flag 1, otherwise in milliseconds by the bytes per second
// of the format. E_INVALIDARG for a null pointer, 0x800401F0 (not initialised) while +0x10 is null.
long __stdcall Object_001E3B90::func_0016B9F0(unsigned __int64 *length, unsigned long flags)
{
    if (ready) {
        if (length) {
            if (flags & 1) {
                *length = end - start;
                return 0;
            }
            *length = (__int64)(end - start) * 1000 / format->bytesPerSecond;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
