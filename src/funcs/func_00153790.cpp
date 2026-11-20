void __stdcall func_00199DB0(unsigned long first, unsigned long second, unsigned long third);

// A class whose table is at 0x1E1328 (6 slots).
struct Object_001E1328 {
    virtual long __stdcall func_00153790(unsigned long first, unsigned long second, unsigned long third);  // slot 5
};

long __stdcall Object_001E1328::func_00153790(unsigned long first, unsigned long second, unsigned long third)
{
    func_00199DB0(first, second, third);
    return 0;
}
