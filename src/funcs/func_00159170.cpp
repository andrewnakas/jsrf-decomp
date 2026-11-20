// A class whose table is at 0x1E1610 (11 slots; Release 0x159420, created by 0x159450).
struct Object_001E1610 {
    virtual unsigned long __stdcall func_00159170();  // slot 1

    char unknown_04[0x18];
    unsigned long references;
};

// AddRef: counts one more reference and returns the new count.
unsigned long __stdcall Object_001E1610::func_00159170()
{
    return ++references;
}
