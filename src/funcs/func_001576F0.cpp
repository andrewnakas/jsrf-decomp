// A class whose table is at 0x1E141C (12 slots).
struct Object_001E141C {
    virtual unsigned long __stdcall func_001576F0();  // slot 1

    char unknown_04[0x1038];
    unsigned long references;
};

// AddRef: counts one more reference and returns the new count.
unsigned long __stdcall Object_001E141C::func_001576F0()
{
    return ++references;
}
