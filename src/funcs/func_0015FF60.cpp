struct Guid;

// MGameInput8, the class its factory (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings) creates; its table
// is at 0x1E1900.
struct MGameInput8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall func_0015FF60(void *value);

    char unknown_04[0x10];
    void *value;
    int count;
};

// Slot 4: keeps the value at +0x14 and clears the word at +0x18.
long __stdcall MGameInput8::func_0015FF60(void *value)
{
    this->value = value;
    count = 0;
    return 0;
}
