/* sym: ??1Object_001E1598@@QAE@XZ = 0x00158EF0 */
struct Vector4;

// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual long __stdcall func_00157F00_2(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded
    virtual unsigned long __stdcall func_00158EE0();  // slot 1
    virtual unsigned long __stdcall func_0014D080_7();  // slot 2: returns 0, folded
    virtual long __stdcall func_00158D70();  // slot 3
    virtual unsigned long __stdcall func_00158D90();  // slot 4
    virtual long __stdcall func_00158DB0(const Vector4 *value);  // slot 5
    virtual long __stdcall func_00158E30(const void *source, unsigned int count, unsigned int stride);  // slot 6
    virtual void __stdcall func_00158E80();  // slot 7
    virtual void __stdcall func_00158ED0(float value);  // slot 8
    virtual void __stdcall func_00157F20_5(unsigned long value);  // slot 9: does nothing, folded

    ~Object_001E1598();
};

// The destructor: only the table pointer is reset.
Object_001E1598::~Object_001E1598()
{
}
