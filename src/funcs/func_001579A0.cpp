// A class whose table is at 0x1E141C (12 slots; Release 0x1579A0).
struct Object_001E141C {
    virtual long __stdcall func_001577C0(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001576F0();  // slot 1
    virtual unsigned long __stdcall func_001579A0();  // slot 2
    virtual long __stdcall func_00157800(unsigned long first, unsigned long second, unsigned long third);  // slot 3
    virtual void __stdcall func_00157960();  // slot 4
    virtual long __stdcall func_00157100(unsigned long first, unsigned long second);  // slot 5
    virtual long __stdcall func_001571E0(unsigned long first, unsigned long second);  // slot 6
    virtual long __stdcall func_001572D0();  // slot 7
    virtual long __stdcall func_00157300();  // slot 8
    virtual void __stdcall func_0015A1C0(unsigned long x, unsigned long y, const unsigned short *text);  // slot 9
    virtual long __stdcall func_00157320(unsigned long first, unsigned long second);  // slot 10
    virtual long __stdcall func_001574C0(unsigned long first, unsigned long second, unsigned long third);  // slot 11

    ~Object_001E141C() {}

    char unknown_04[0x1038];
    unsigned long references;
};

void __stdcall func_001570B0(Object_001E141C *object);

// Release: the last reference lets func_001570B0 take the object apart, then deletes it.
unsigned long __stdcall Object_001E141C::func_001579A0()
{
    if (--references == 0) {
        func_001570B0(this);
        delete this;
        return 0;
    }
    return references;
}
