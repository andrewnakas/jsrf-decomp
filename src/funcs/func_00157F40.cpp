/* sym: ??1Object_001E1478@@QAE@XZ = 0x00157F40 */
// The base of the classes whose tables are at 0x1E1478, 0x1E1498 and 0x1E14B8 (created by 0x158490).
struct Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0_2();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_0014D080_5();  // slot 2: returns 0, folded
    virtual long __stdcall func_00157F10(unsigned long value);  // slot 3
    virtual void __stdcall func_00157F20(unsigned long value);  // slot 4
    virtual void __stdcall func_00157F30(unsigned long first, unsigned long second);  // slot 5
    virtual void __stdcall func_00157F20_1(unsigned long value);  // slot 6: the same folded function
    virtual void __stdcall func_00157F20_2(unsigned long value);  // slot 7: the same folded function

    ~Object_001E1478();
};

// The destructor: only the table pointer is reset.
Object_001E1478::~Object_001E1478()
{
}
