struct Guid;

// The class whose table is at 0x1E2008 (9 slots, the same Release as 0x1E1FE4).
struct Object_001E2008 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall func_00165CD0(int value);

    char unknown_04[0x948];
    int value;
};

// Slot 6: keeps the value at +0x94c; 0 stands for 20.
long __stdcall Object_001E2008::func_00165CD0(int value)
{
    if (!value)
        value = 20;
    this->value = value;
    return 0;
}
