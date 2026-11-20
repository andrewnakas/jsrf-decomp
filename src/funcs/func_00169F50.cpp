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
    virtual long __stdcall slot8();
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
    virtual long __stdcall func_00169F50();

    void *outer;
    long references;
    Sound *sound;
    BufferList buffers;
};

// Slot 4: calls slot 8 of every entry of the list at +0x10 and returns the last result (0 for an empty list).
// 0x800401F0 (not initialised) without the DirectSound object at +0xc.
long __stdcall Object_001E3B00::func_00169F50()
{
    if (sound) {
        long result = 0;
        for (Buffer **entry = buffers.first; entry != buffers.last; ++entry) {
            if (*entry)
                result = (*entry)->slot8();
        }
        return result;
    }
    return 0x800401F0;
}
