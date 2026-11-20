// The base of the classes whose tables are at 0x1E17BC (constructor 0x15F1C0) and 0x1E17E0 (constructor 0x15F280).
struct Object_001E17BC {
    virtual long __stdcall func_0015F1E0(unsigned long first, unsigned long second, unsigned long third);  // slot 3
};

// Slot 3: does nothing here (0x1E17E0 overrides it with 0x15F860).
long __stdcall Object_001E17BC::func_0015F1E0(unsigned long first, unsigned long second, unsigned long third)
{
    return 0;
}
