struct Buffer;

// Puts the object in the list at data_00265120 (E_OUTOFMEMORY when the list cannot grow).
long __stdcall func_00159E90(void *link, void *object);

// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual long __stdcall func_00157F00_2(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded

    long __stdcall func_00158CB0(unsigned long first, unsigned long second);
    long __stdcall func_0015C160(unsigned long first, unsigned long second);

    Buffer *buffer;
};

// Sets the object up (func_00158CB0) and, when that works, puts it in the list.
long __stdcall Object_001E1598::func_0015C160(unsigned long first, unsigned long second)
{
    long result = func_00158CB0(first, second);
    if (result < 0)
        return result;
    func_00159E90(&buffer, this);
    return 0;
}
