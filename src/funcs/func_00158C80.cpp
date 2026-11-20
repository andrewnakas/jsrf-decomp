/* sym: ?func_0014D080_6@Object_001E1508@@UAGKXZ = 0x00158C80 */
/* sym: ??1Object_001E14D8@@QAE@XZ = 0x00158A70 */
// The base of the classes whose tables are at 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual long __stdcall func_00157F00_1(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded
    virtual unsigned long __stdcall func_00158A30();  // slot 1
    virtual unsigned long __stdcall func_0014D080_6();  // slot 2: returns 0, folded

    ~Object_001E14D8();

    unsigned long words[0x48];
    unsigned long references;
};

// Kind 0 of 0x158A80; its Release is folded with kinds 1 and 2 (0x1E1538, 0x1E1568).
struct Object_001E1508 : Object_001E14D8 {
    virtual unsigned long __stdcall func_0014D080_6();  // slot 2, at 0x158C80
};

void __stdcall func_0015B3E0(Object_001E14D8 *object);

// Release: the last reference lets func_0015B3E0 take the object apart, then deletes it.
unsigned long __stdcall Object_001E1508::func_0014D080_6()
{
    if (--references == 0) {
        func_0015B3E0(this);
        delete static_cast<Object_001E14D8 *>(this);
        return 0;
    }
    return references;
}
