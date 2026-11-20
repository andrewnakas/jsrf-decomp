/* sym: ?func_00158A60@Object_001E1508@@UAGJKKK@Z = 0x0015B400 */
struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual long __stdcall slot5();
};

void func_00158DF0(void *destination, const void *source, unsigned int count, unsigned int stride);

// The base of the classes whose tables are at 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual long __stdcall func_00158A60(unsigned long first, unsigned long second, unsigned long third);  // slot 6
};

// The class whose table is at 0x1E1508: its buffer is at +0x104.
struct Object_001E1508 : Object_001E14D8 {
    virtual long __stdcall func_00158A60(unsigned long first, unsigned long second, unsigned long third);  // slot 6, at 0x15B400

    char unknown_04[0x100];
    Buffer *buffer;
};

// Slot 6: locks the buffer (its slot 4), copies count 16-byte entries spaced stride apart from the source into it
// (func_00158DF0) and unlocks it (slot 5).
long __stdcall Object_001E1508::func_00158A60(unsigned long first, unsigned long second, unsigned long third)
{
    void *data = 0;
    long result = buffer->slot4(&data, 0);

    if (result < 0)
        return result;
    func_00158DF0(data, (const void *)first, second, third);
    buffer->slot5();
    return 0;
}
