// The base of the classes whose tables are at 0x1E1290 (destructor 0x152690), 0x1E1298, 0x1E12B8 and 0x1E12D8
// (created by 0x152BC0); all four share this QueryInterface.
struct Object_001E1290 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0

    void func_001523D0(unsigned long second, unsigned long first, unsigned long value);
};

// The class whose table is at 0x1E1298 (created by 0x152BC0).
struct Object_001E1298 : Object_001E1290 {
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall func_00152740(unsigned long *second, unsigned long *first, unsigned long unused);  // slot 4
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual long __stdcall func_001525D0(unsigned long value);  // slot 7
};

// Gets the pair (slot 4), hands it and the value to func_001523D0 and calls slot 5.
long __stdcall Object_001E1298::func_001525D0(unsigned long value)
{
    unsigned long second = 0;
    unsigned long first = 0;
    long result = func_00152740(&second, &first, 0);

    if (result >= 0) {
        func_001523D0(second, first, value);
        slot5();
    }
    return result;
}
