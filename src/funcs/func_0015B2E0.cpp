/* sym: ?func_00157F20_2@Object_001E14B8@@UAGXK@Z = 0x0015B2E0 */
// The base of the classes whose tables are at 0x1E1498 and 0x1E14B8 (created by 0x158490).
struct Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0_2();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_0014D080_5();  // slot 2: returns 0, folded
    virtual long __stdcall func_00157F10(unsigned long value);  // slot 3
    virtual void __stdcall func_00157F20(unsigned long value);  // slot 4
    virtual void __stdcall func_00157F30(unsigned long first, unsigned long second);  // slot 5
    virtual void __stdcall func_00157F20_1(unsigned long value);  // slot 6: the same folded function
    virtual void __stdcall func_00157F20_2(unsigned long value);  // slot 7: the same folded function
};

// The class whose table is at 0x1E14B8 (kind 1 of 0x158490).
struct Object_001E14B8 : Object_001E1478 {
    virtual void __stdcall func_00157F20_2(unsigned long value);  // slot 7, at 0x15B2E0
};

// Slot 7: hands the value and the word at +8 of what it points at to slot 5.
void __stdcall Object_001E14B8::func_00157F20_2(unsigned long value)
{
    func_00157F30(value, ((const unsigned long *)value)[2]);
}
