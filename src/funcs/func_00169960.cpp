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
    virtual long __stdcall slot6(void *argument);
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
    virtual long __stdcall func_00169960(unsigned int index, void *argument);

    void *outer;
    long references;
    Sound *sound;
    BufferList buffers;
};

// Slot 12: passes the argument on to slot 6 of entry `index` of the list at +0x10 (taken with slot 7, which fails for
// an index past the end or an empty entry). 0x800401F0 (not initialised) without the DirectSound object at +0xc.
long __stdcall Object_001E3B00::func_00169960(unsigned int index, void *argument)
{
    long result;
    if (sound) {
        Buffer *buffer;
        result = slot7(index, &buffer);
        if (result >= 0) {
            result = buffer->slot6(argument);
            if (buffer)
                buffer->slot2();
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
