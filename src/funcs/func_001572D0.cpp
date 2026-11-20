struct Source {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(unsigned long *first, unsigned long *second, unsigned long flags);
    virtual long __stdcall slot5();
};

// A class whose table is at 0x1E141C (12 slots).
struct Object_001E141C {
    virtual long __stdcall func_001572D0();  // slot 7

    char unknown_04[0x1014];
    Source *source;
    char unknown_101c[0x14];
    unsigned long first;
    unsigned long second;
};

// Slot 4 of the object at +0x1018 with the words at +0x1030 and +0x1034.
long __stdcall Object_001E141C::func_001572D0()
{
    return source->slot4(&first, &second, 0);
}
