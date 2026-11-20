struct Guid;
struct Sound;

// The object slot 9 takes: slot 5 is called with the second argument.
struct Target {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall slot5(void *argument);
};

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
    virtual long __stdcall func_00169580(Target *target, void *argument);

    void *outer;
    long references;
    Sound *sound;
    BufferList buffers;
};

// Slot 9: passes the argument on to slot 5 of the object; E_INVALIDARG for a null object. The voice itself is not used.
long __stdcall Object_001E3B00::func_00169580(Target *target, void *argument)
{
    if (target)
        return target->slot5(argument);
    return 0x80070057;
}
