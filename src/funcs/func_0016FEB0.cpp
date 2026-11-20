struct Guid;

// The class whose table is at 0x1E3C08.
struct Object_001E3C08 {
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
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual long __stdcall func_0016FEB0(int *value);

    char unknown_04[0xc];
    void *device;
    char unknown_14[0xe0];
    int value;
};

// Slot 17: copies the word at +0xf4 out once there is an object at +0x10 (else 0x800401F0, not initialised);
// E_INVALIDARG for a null pointer. The same as func_0016B960 of 0x1E3B90, at another offset.
long __stdcall Object_001E3C08::func_0016FEB0(int *value)
{
    if (device) {
        if (value) {
            *value = this->value;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
