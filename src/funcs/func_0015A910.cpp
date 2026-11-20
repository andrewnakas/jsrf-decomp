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
    virtual long __stdcall func_0015A910();  // slot 3

    Buffer *buffer;
    char unknown_08[4];
    unsigned long current;
    char unknown_10[8];
    unsigned long start;
    unsigned long position;
    unsigned long value;
};

// Copies the word at +0x18 to +0xC, clears +0x20 and passes +0x1C to slot 4 of the object at +4.
long __stdcall Object_001E144C::func_0015A910()
{
    current = start;
    value = 0;
    return buffer->slot4(&position, 0);
}
