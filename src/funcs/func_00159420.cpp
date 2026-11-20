struct Record;

// A class whose table is at 0x1E1610 (11 slots).
struct Object_001E1610 {
    virtual long __stdcall func_00159180(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_00159170();  // slot 1
    virtual unsigned long __stdcall func_00159420();  // slot 2
    virtual long __stdcall func_00159080();  // slot 3
    virtual unsigned long __stdcall func_001590B0();  // slot 4
    virtual long __stdcall func_0015C5D0(unsigned long value);  // slot 5
    virtual long __stdcall func_0015C600(unsigned long first, unsigned long second, unsigned long third);  // slot 6
    virtual long __stdcall func_001590D0();  // slot 7
    virtual long __stdcall func_00159330(const Record *records, unsigned int count);  // slot 8
    virtual long __stdcall func_0015C670(unsigned long value);  // slot 9
    virtual long __stdcall func_0015C6E0(int position);  // slot 10

    ~Object_001E1610() {}

    char unknown_04[0x18];
    unsigned long references;
};

void __stdcall func_001592D0(Object_001E1610 *object);

// Release: the last reference lets func_001592D0 take the object apart, then deletes it.
unsigned long __stdcall Object_001E1610::func_00159420()
{
    if (--references == 0) {
        func_001592D0(this);
        delete this;
        return 0;
    }
    return references;
}
