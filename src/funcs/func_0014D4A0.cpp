// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014D4A0();  // slot 1

    char unknown_04[0x1C];
    unsigned long references;
};

// AddRef. The linker folded it with the AddRef of the unrelated class at 0x1E1248 (slot 1 there too).
unsigned long __stdcall Object_001E10E8::func_0014D4A0()
{
    return ++references;
}
