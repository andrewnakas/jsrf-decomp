struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(unsigned long *position, unsigned long flags);
    virtual long __stdcall slot5();
};

// A class whose table is at 0x1E1610 (11 slots; Release 0x159420, created by 0x159450).
struct Object_001E1610 {
    virtual unsigned long __stdcall func_001590B0();  // slot 4

    Buffer *buffer;
    char unknown_08[0xc];
    unsigned long position;
    unsigned long value;
};

// Slot 5 of the object at +4, then returns the word at +0x18.
unsigned long __stdcall Object_001E1610::func_001590B0()
{
    buffer->slot5();
    return value;
}
