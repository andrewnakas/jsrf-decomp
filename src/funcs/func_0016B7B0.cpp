struct Guid;

// The class whose table is at 0x1E3B90 (30 slots; the destructor is the last).
struct Object_001E3B90 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall func_0016B7B0(unsigned long *flags);

    char unknown_04[0xc];
    void *ready;
    char unknown_14[0x230];
    unsigned long state;
    char unknown_248[0x3c];
    unsigned long caps;
};

// Slot 9: builds flags from the word at +0x284 (its bits 1, 4 and 8 give 1, 4 and 8) and bit 1 of the word at +0x244
// (0x80000000). E_INVALIDARG for a null pointer, 0x800401F0 (not initialised) while +0x10 is null.
long __stdcall Object_001E3B90::func_0016B7B0(unsigned long *flags)
{
    long result;
    if (ready) {
        if (flags) {
            unsigned long value = 0;
            if (caps & 1)
                value = 1;
            if (caps & 4)
                value |= 4;
            if (caps & 8)
                value |= 8;
            if (state & 1)
                value |= 0x80000000;
            *flags = value;
            result = 0;
        } else {
            result = 0x80070057;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
