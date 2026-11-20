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
    virtual long __stdcall func_00159080();  // slot 3

    Buffer *buffer;
    char unknown_08[0xc];
    unsigned long position;
    unsigned long value;
};

// Clears the words at +0x14 and +0x18 and passes the first to slot 4 of the object at +4.
long __stdcall Object_001E1610::func_00159080()
{
    position = 0;
    value = 0;
    return buffer->slot4(&position, 0);
}
