struct Guid;
struct Sound;

// The objects in the voice's list at +0x10 (slot 7 of the voice gives them out; slot 2 lets go of one).
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
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual long __stdcall slot24(void *argument);
};

// A std::vector of pointers.
struct BufferList {
    char allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;
};

// The class whose table is at 0x1E3B00: the voices MGameSound8 makes (0x30 bytes).
struct Object_001E3B00 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall slot7(unsigned int index, Buffer **buffer);
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
    virtual void slot28();
    virtual void slot29();
    virtual long __stdcall func_00169BB0(unsigned int index, void *argument);

    void *outer;
    long references;
    Sound *sound;
    BufferList buffers;
};

// Slot 30: passes the argument on to slot 24 of entry `index` of the list at +0x10 (taken with slot 7, which fails for
// an index past the end or an empty entry). 0x800401F0 (not initialised) without the DirectSound object at +0xc.
long __stdcall Object_001E3B00::func_00169BB0(unsigned int index, void *argument)
{
    long result;
    if (sound) {
        Buffer *buffer;
        result = slot7(index, &buffer);
        if (result >= 0) {
            result = buffer->slot24(argument);
            if (buffer)
                buffer->slot2();
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
