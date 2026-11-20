struct Guid;
struct Sound;

// The objects in the voice's list at +0x10 (slot 7 of the voice gives them out; slot 2 lets go of one).
struct Buffer {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// A std::vector of pointers.
struct BufferList {
    char allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
    void func_0016ACD0(unsigned int size, Buffer *value);
};

// The class whose table is at 0x1E3B00: the voices MGameSound8 makes (0x30 bytes).
struct Object_001E3B00 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall func_0016AE50(unsigned int index, Buffer *buffer);

    void *outer;
    long references;
    Sound *sound;
    BufferList buffers;
};

// Slot 6: puts the object, with a reference, in entry `index` of the list at +0x10, growing the list to fit (0x16ACD0).
// E_FAIL when the entry is taken, 0x800401F0 (not initialised) without the DirectSound object at +0xc.
long __stdcall Object_001E3B00::func_0016AE50(unsigned int index, Buffer *buffer)
{
    if (sound) {
        if (index >= buffers.size()) {
            unsigned int count = index - buffers.size() + 1;
            buffers.func_0016ACD0(buffers.size() + count, 0);
        }
        if (buffers.first[index])
            return 0x80004005;
        if (buffer)
            buffer->slot1();
        buffers.first[index] = buffer;
        return 0;
    }
    return 0x800401F0;
}
