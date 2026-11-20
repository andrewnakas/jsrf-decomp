// A class whose table is at 0x1E144C (11 slots).
struct Object_001E144C {
    virtual unsigned long __stdcall func_00157CA0();  // slot 1

    char unknown_04[0x20];
    unsigned long references;
};

// AddRef: counts one more reference and returns the new count.
unsigned long __stdcall Object_001E144C::func_00157CA0()
{
    return ++references;
}
