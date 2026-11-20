struct Guid;

// A block of 0x10 bytes whose first word is its size.
struct Caps {
    unsigned long size;
    unsigned long first;
    unsigned long value;
    unsigned long last;
};

// The class whose table is at 0x1E3C08.
struct Object_001E3C08 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall func_0016FDF0(Caps *caps);

    char unknown_04[0x1c];
    unsigned long value;
};

// Slot 4: fills in the caller's block (0x10 bytes): 0, the word at +0x20, 0. E_INVALIDARG for a wrong block.
long __stdcall Object_001E3C08::func_0016FDF0(Caps *caps)
{
    if (caps && caps->size == sizeof(Caps)) {
        caps->first = 0;
        caps->value = value;
        caps->last = 0;
        return 0;
    }
    return 0x80070057;
}
