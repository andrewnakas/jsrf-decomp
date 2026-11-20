struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(unsigned long *position, unsigned long flags);
    virtual long __stdcall slot5();
};

// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual long __stdcall func_00158D70();  // slot 3

    Buffer *buffer;
    char unknown_08[8];
    unsigned long position;
    unsigned long value;
};

// Clears the word at +0x14 and passes +0x10 to slot 4 of the object at +4.
long __stdcall Object_001E1598::func_00158D70()
{
    value = 0;
    return buffer->slot4(&position, 0);
}
