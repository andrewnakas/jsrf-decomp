// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual unsigned long __stdcall func_00158EE0();  // slot 1

    char unknown_04[0x14];
    unsigned long references;
};

// AddRef: counts one more reference and returns the new count.
unsigned long __stdcall Object_001E1598::func_00158EE0()
{
    return ++references;
}
