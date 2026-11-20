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
    virtual long __stdcall func_00166240(int value);

    char unknown_04[0x14];
    int value;
    char unknown_1c[0x14];
    int tag;
};

// Slot 10: keeps the value at +0x18 (0 stands for 20) once the word at +0x30 is 0x5c; before that it fails with
// 0x800401F0 (not initialised).
long __stdcall Object_001E202C::func_00166240(int value)
{
    if (tag == 0x5c) {
        if (!value)
            value = 20;
        this->value = value;
        return 0;
    }
    return 0x800401F0;
}
