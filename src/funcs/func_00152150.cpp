// A class whose table is at 0x1E1270 (8 slots).
struct Object_001E1270 {
    virtual unsigned long __stdcall func_00152150();  // slot 1

    char unknown_04[0x604];
    unsigned long references;
};

// AddRef: counts one more reference and returns the new count.
unsigned long __stdcall Object_001E1270::func_00152150()
{
    return ++references;
}
