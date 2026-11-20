// A class whose table is at 0x1E1798 (9 slots, constructor 0x15F190): its keys are at +0x44.
struct Object_001E1798 {
    virtual long __stdcall func_0015F580(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0015F1B0();  // slot 1

    char unknown_04[0x48];
    unsigned long references;
};

// AddRef. The linker folded it: it is also slot 1 of the tables at 0x1E17BC and 0x1E17E0.
unsigned long __stdcall Object_001E1798::func_0015F1B0()
{
    return ++references;
}
