struct Guid;

// The class whose table is at 0x1E2008 (9 slots, the same Release as 0x1E1FE4).
struct Object_001E2008 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall func_00165D00(int *value);

    char unknown_04[0x948];
    int value;
};

// Slot 7: copies the word at +0x94c out; E_INVALIDARG for a null pointer.
long __stdcall Object_001E2008::func_00165D00(int *value)
{
    if (value) {
        *value = this->value;
        return 0;
    }
    return 0x80070057;
}
