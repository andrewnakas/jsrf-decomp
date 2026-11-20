void __stdcall func_001997C0(void *object, unsigned long first, unsigned long second, unsigned long third, unsigned long fourth);

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_00155E30(unsigned long first, unsigned long second);  // slot 4

    void *object;
};

long __stdcall Object_001E10E8::func_00155E30(unsigned long first, unsigned long second)
{
    func_001997C0(object, 0, 0, first, second);
    return 0;
}
