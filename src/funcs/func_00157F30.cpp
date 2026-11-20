// The base of the classes whose tables are at 0x1E1478, 0x1E1498 and 0x1E14B8 (created by 0x158490).
struct Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0_2();  // slot 1
    virtual unsigned long __stdcall func_0014D080_5();  // slot 2
    virtual long __stdcall func_00157F10(unsigned long value);  // slot 3
    virtual void __stdcall func_00157F20(unsigned long value);  // slot 4
    virtual void __stdcall func_00157F30(unsigned long first, unsigned long second);  // slot 5
};

// Does nothing. The linker folded it: it is also slot 8 of the table at 0x1E17BC.
void __stdcall Object_001E1478::func_00157F30(unsigned long first, unsigned long second)
{
}
