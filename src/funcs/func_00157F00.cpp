// The base of the classes whose tables are at 0x1E1478, 0x1E1498 and 0x1E14B8 (created by 0x158490).
struct Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0
};

// E_UNEXPECTED. The linker folded it: it is also slot 0 of the tables at 0x1E14D8, 0x1E1598 and 0x1E17BC.
long __stdcall Object_001E1478::func_00157F00(const void *iid, void **object)
{
    return 0x8000FFFF;
}
