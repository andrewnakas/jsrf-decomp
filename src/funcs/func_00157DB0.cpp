// A class whose table is at 0x1E144C (11 slots).
struct Object_001E144C {
    virtual long __stdcall func_00157D70(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_00157CA0();  // slot 1
    virtual unsigned long __stdcall func_00157DB0();  // slot 2
    virtual long __stdcall func_0015A910();  // slot 3
    virtual unsigned long __stdcall func_0015A940();  // slot 4
    virtual long __stdcall func_0015A880(unsigned long first, unsigned long second);  // slot 5
    virtual long __stdcall func_0015A560(unsigned long first, unsigned long second, unsigned long third);  // slot 6
    virtual long __stdcall func_00157C50();  // slot 7
    virtual void __stdcall func_00157BF0(int index, float value);  // slot 8
    virtual void __stdcall func_0015A960(unsigned long first, int kind);  // slot 9
    virtual long __stdcall func_0015A660(int position);  // slot 10

    ~Object_001E144C() {}

    char unknown_04[0x20];
    unsigned long references;
};

void __stdcall func_00157BB0(Object_001E144C *object);

// Release: the last reference lets func_00157BB0 take the object apart, then deletes it.
unsigned long __stdcall Object_001E144C::func_00157DB0()
{
    if (--references == 0) {
        func_00157BB0(this);
        delete this;
        return 0;
    }
    return references;
}
