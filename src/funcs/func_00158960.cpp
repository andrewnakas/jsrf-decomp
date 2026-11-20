struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual long __stdcall slot5();
};

// The base of the classes whose tables are at 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual long __stdcall func_00158960();  // slot 4

    char unknown_04[0x100];
    Buffer *buffer;
    char unknown_108[0xC];
    unsigned long *target;
    unsigned long *source;
    char unknown_11C[4];
    long value_120;
};

// Slot 4: unlocks the buffer (its slot 5), copies the four words at source to target and returns the value at
// +0x120.
long __stdcall Object_001E14D8::func_00158960()
{
    buffer->slot5();
    target[0] = source[0];
    target[1] = source[1];
    target[2] = source[2];
    target[3] = source[3];
    return value_120;
}
