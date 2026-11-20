// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014D4A0();  // slot 1
    virtual unsigned long __stdcall func_0014D080();  // slot 2
};

// Returns 0. The linker folded it: it also fills slots 5 and 7 of this table and slots 44 and 45 of the device
// wrapper's table at 0x1E0F00.
unsigned long __stdcall Object_001E10E8::func_0014D080()
{
    return 0;
}
