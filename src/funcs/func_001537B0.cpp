// A class whose table is at 0x1E1328 (6 slots).
struct Object_001E1328 {
    virtual unsigned long __stdcall func_001537B0();  // slot 1

    char unknown_04[4];
    unsigned long references;
};

// AddRef: counts one more reference and returns the new count.
unsigned long __stdcall Object_001E1328::func_001537B0()
{
    return ++references;
}
