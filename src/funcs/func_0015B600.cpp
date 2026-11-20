// Puts the object in the list at data_00265120 (E_OUTOFMEMORY when the list cannot grow).
long __stdcall func_00159E90(void *link, void *object);

// The base of the classes whose tables are at 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual long __stdcall slot0();

    long __stdcall func_001585D0(unsigned long first, unsigned long second);
    long __stdcall func_0015B600(unsigned long first, unsigned long second);

    void *value_04;
};

// Sets the object up (func_001585D0) and, when that works, puts it in the list.
long __stdcall Object_001E14D8::func_0015B600(unsigned long first, unsigned long second)
{
    long result = func_001585D0(first, second);
    if (result < 0)
        return result;
    func_00159E90(&value_04, this);
    return 0;
}
