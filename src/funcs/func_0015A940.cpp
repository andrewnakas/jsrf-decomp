struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(unsigned long *position, unsigned long flags);
    virtual long __stdcall slot5();
};

// A class whose table is at 0x1E144C (11 slots).
struct Object_001E144C {
    virtual unsigned long __stdcall func_0015A940();  // slot 4

    Buffer *buffer;
    char unknown_08[0x14];
    unsigned long position;
    unsigned long value;
};

// Slot 5 of the object at +4, then returns the word at +0x20.
unsigned long __stdcall Object_001E144C::func_0015A940()
{
    buffer->slot5();
    return value;
}
