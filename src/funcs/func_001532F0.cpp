// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 {
    virtual long __stdcall func_00153300(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0();  // slot 1

    unsigned long references;
};

// AddRef. The linker folded it: it is also slot 1 of the tables at 0x1E13F0 and 0x1E1478 (and its children).
unsigned long __stdcall Object_001E12F8::func_001532F0()
{
    return ++references;
}
