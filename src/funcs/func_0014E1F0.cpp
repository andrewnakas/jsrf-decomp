// A class whose table is at 0x1E1220 (6 slots).
struct Object_001E1220 {
    virtual long __stdcall func_0014E200(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014E1F0();  // slot 1

    char unknown_04[0x10];
    unsigned long references;
};

// AddRef. The linker folded it: it is also slot 1 of the tables at 0x1E1290 (and its children) and 0x1E1640.
unsigned long __stdcall Object_001E1220::func_0014E1F0()
{
    return ++references;
}
