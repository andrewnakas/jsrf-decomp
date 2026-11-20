// The base of the classes whose tables are at 0x1E14D8, 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual unsigned long __stdcall func_00158A30();  // slot 1

    char unknown_04[0x120];
    unsigned long references;
};

// AddRef: counts one more reference and returns the new count.
unsigned long __stdcall Object_001E14D8::func_00158A30()
{
    return ++references;
}
