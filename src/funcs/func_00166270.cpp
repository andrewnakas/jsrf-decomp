struct Guid;

// The class whose table is at 0x1E202C (13 slots; the destructor is the last).
struct Object_001E202C {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual long __stdcall func_00166270(int *value);

    char unknown_04[0x14];
    int value;
    char unknown_1c[0x14];
    int tag;
};

// Slot 11: copies the value at +0x18 out once the word at +0x30 is 0x5c (else 0x800401F0, not initialised);
// E_INVALIDARG for a null pointer.
long __stdcall Object_001E202C::func_00166270(int *value)
{
    if (tag == 0x5c) {
        if (value) {
            *value = this->value;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
