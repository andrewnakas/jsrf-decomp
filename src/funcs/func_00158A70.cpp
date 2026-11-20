/* sym: ??1Object_001E14D8@@QAE@XZ = 0x00158A70 */
// The base of the classes whose tables are at 0x1E14D8, 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual long __stdcall func_00157F00_1(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded
    virtual unsigned long __stdcall func_00158A30();  // slot 1
    virtual unsigned long __stdcall func_0014D080_6();  // slot 2: returns 0, folded
    virtual long __stdcall func_001588F0();  // slot 3
    virtual long __stdcall func_00158960();  // slot 4
    virtual long __stdcall func_00158A50(unsigned long value);  // slot 5
    virtual long __stdcall func_00158A60(unsigned long first, unsigned long second, unsigned long third);  // slot 6
    virtual void __stdcall func_00158780();  // slot 7
    virtual void __stdcall func_001587F0(float value, unsigned long unused);  // slot 8
    virtual void __stdcall func_00158810(unsigned long first, unsigned long second);  // slot 9
    virtual void __stdcall func_00157F20_3(unsigned long value);  // slot 10: does nothing, folded
    virtual void __stdcall func_00157F20_4(unsigned long value);  // slot 11: the same folded function

    ~Object_001E14D8();
};

// The destructor: only the table pointer is reset.
Object_001E14D8::~Object_001E14D8()
{
}
