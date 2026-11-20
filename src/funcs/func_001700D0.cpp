struct Guid;

// The format at +0xf4: the word at +8 is the rate the time is counted in.
struct Format {
    unsigned long unknown_0[2];
    unsigned long rate;
};

// The buffer at +0x12c (slot 21 gives out the position).
struct Buffer {
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
    virtual long __stdcall slot21(void *argument1, void *argument2, unsigned long *position);
};

// The class whose table is at 0x1E3C08.
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
    virtual long __stdcall func_001700D0(void *argument1, void *argument2);

    char unknown_04[0xf0];
    Format *format;
    char unknown_f8[0x34];
    Buffer *buffer;
};

// Slot 28: gives out the buffer's position (its slot 21) as a 64-bit value: as it is with flag 1 in the second
// argument, otherwise times 1000 over the rate at +8 of the format at +0xf4. 0x80070057 (E_INVALIDARG) without a
// place for it, 0x800401F0 (not initialised) while +0x12c is null.
long __stdcall Object_001E3C08::func_001700D0(void *argument1, void *argument2)
{
    long result;
    if (buffer) {
        unsigned __int64 *time = (unsigned __int64 *)argument1;
        if (time) {
            *time = 0;
            unsigned long position;
            result = buffer->slot21(0, 0, &position);
            if (result >= 0) {
                if ((unsigned long)argument2 & 1)
                    *time = position;
                else
                    *time = (__int64)position * 1000 / format->rate;
            }
        } else {
            result = 0x80070057;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
