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

    void func_0016AEF0(Buffer *const &value);
};

// A std::vector of those lists.
struct GroupList {
    char allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
    void func_0016B6A0(unsigned int size);
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
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual long __stdcall func_0016B6D0(unsigned int group, Buffer *buffer);

    void *outer;
    long references;
    Sound *sound;
    BufferList buffers;
    GroupList groups;
};

// Slot 10: appends the object to list `group` of the lists at +0x20 (0x16AEF0), adding empty lists to reach it
// (0x16B6A0).
long __stdcall Object_001E3B00::func_0016B6D0(unsigned int group, Buffer *buffer)
{
    if (group >= groups.size())
        groups.func_0016B6A0(group + 1);
    groups.first[group].func_0016AEF0(buffer);
    return 0;
}
