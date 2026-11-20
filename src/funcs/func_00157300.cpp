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
    virtual long __stdcall func_00157300();  // slot 8

    char unknown_04[0x1014];
    Source *source;
};

long __stdcall Object_001E141C::func_00157300()
{
    return source->slot5();
}
