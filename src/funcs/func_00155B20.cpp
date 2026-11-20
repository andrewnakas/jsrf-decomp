void __stdcall func_001900D0(unsigned long stage, void *object, unsigned long extra);

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_00155B20(unsigned long stage);  // slot 8

    void *object;
    char unknown_08[8];
    unsigned long extra;
};

long __stdcall Object_001E10E8::func_00155B20(unsigned long stage)
{
    func_001900D0(stage, object, extra);
    return 0;
}
