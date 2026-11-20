struct Interface_00265110;

// A class whose table is at 0x1E13F0 (11 slots).
struct Object_001E13F0 {
    virtual long __stdcall func_00156D60(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0_1();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_00156DC0();  // slot 2
    virtual long __stdcall func_0015A020(Interface_00265110 *source);  // slot 3
    virtual long __stdcall func_00159D70(unsigned long first, unsigned long second, void **object);  // slot 4
    virtual long __stdcall func_00159450(unsigned long first, unsigned long second, unsigned long third, void **object);  // slot 5
    virtual long __stdcall func_00158F00(unsigned long first, unsigned long second, void **object);  // slot 6
    virtual long __stdcall func_00158A80(unsigned long first, unsigned long second, void **object);  // slot 7
    virtual long __stdcall func_00158490(unsigned long first, unsigned long second, void **object);  // slot 8
    virtual long __stdcall func_00157CB0(unsigned long first, unsigned long second, void **object);  // slot 9
    virtual long __stdcall func_00157710(unsigned long first, unsigned long second, unsigned long third, void **object);  // slot 10

    ~Object_001E13F0() {}

    unsigned long references;
};

void __stdcall func_0015A110(Object_001E13F0 *object);

// Release: the last reference lets func_0015A110 take the object apart, then deletes it.
unsigned long __stdcall Object_001E13F0::func_00156DC0()
{
    if (--references == 0) {
        func_0015A110(this);
        delete this;
        return 0;
    }
    return references;
}
