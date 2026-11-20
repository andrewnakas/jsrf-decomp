/* sym: ??1Object_001E10E8@@QAE@XZ = 0x0014D4B0 */
// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014D4A0();  // slot 1
    virtual unsigned long __stdcall func_0014D080();  // slot 2: returns 0
    virtual long __stdcall func_00155E50(int kind);  // slot 3
    virtual long __stdcall func_00155E30(unsigned long first, unsigned long second);  // slot 4
    virtual unsigned long __stdcall func_0014D080_1();  // slot 5: the same folded function
    virtual long __stdcall func_00156030(unsigned long *value, unsigned long unused);  // slot 6
    virtual unsigned long __stdcall func_0014D080_2();  // slot 7: the same folded function
    virtual long __stdcall func_00155B20(unsigned long stage);  // slot 8
    virtual long __stdcall func_00155B40();  // slot 9
    virtual long __stdcall func_00155B80();  // slot 10
    virtual long __stdcall func_00155BC0();  // slot 11
    virtual long __stdcall func_00155EF0();  // slot 12
    virtual long __stdcall func_00155C00(unsigned int count);  // slot 13
    virtual long __stdcall func_00155C30(unsigned int count);  // slot 14
    virtual long __stdcall func_00155F40(unsigned int count, unsigned int start);  // slot 15
    virtual long __stdcall func_00155CE0();  // slot 16
    virtual long __stdcall func_00155D20();  // slot 17
    virtual long __stdcall func_00155D60();  // slot 18
    virtual long __stdcall func_00155DA0(unsigned int count);  // slot 19
    virtual long __stdcall func_00155DD0(unsigned int count);  // slot 20
    virtual long __stdcall func_00155E00(unsigned int count);  // slot 21
    virtual long __stdcall func_00155F90();  // slot 22
    virtual long __stdcall func_00155FE0(unsigned int count, unsigned int start);  // slot 23
    virtual long __stdcall func_00155C70();  // slot 24
    virtual long __stdcall func_00155CB0(unsigned int count);  // slot 25

    ~Object_001E10E8();
};

// The destructor: only the table pointer is reset.
Object_001E10E8::~Object_001E10E8()
{
}
