/* sym: ?func_001587F0@Object_001E1538@@UAGXMK@Z = 0x0015B630 */
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
};

// The class whose table is at 0x1E1538 (created by 0x158A80).
struct Object_001E1538 : Object_001E14D8 {
    virtual void __stdcall func_001587F0(float value, unsigned long second);  // slot 8, at 0x15B630

    char unknown_04[0x108];
    float value_10C;
    char unknown_110[0x18];
    unsigned long value_128;
};

// Keeps the float at +0x10C and the second value at +0x128.
void __stdcall Object_001E1538::func_001587F0(float value, unsigned long second)
{
    value_10C = value;
    value_128 = second;
}
