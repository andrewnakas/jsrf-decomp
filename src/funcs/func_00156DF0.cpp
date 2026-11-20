struct Guid;
struct Interface_00265110;
extern const Guid data_001E1758;

// The factory object whose table is at 0x1E13F0 (11 slots, 8 bytes; slots 4 to 10 create the other objects).
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

    Object_001E13F0() : references(0) {}
    ~Object_001E13F0() {}

    unsigned long references;
};

// Creates the factory object, gets its interface data_001E1758 into *object and sets it up (slot 3) with the
// interface. E_OUTOFMEMORY when the allocation fails; on a failure *object is null.
long __stdcall func_00156DF0(Interface_00265110 *source, void **object)
{
    Object_001E13F0 *created = new Object_001E13F0;
    if (created) {
        long result = created->func_00156D60(&data_001E1758, object);
        if (result >= 0) {
            result = created->func_0015A020(source);
            if (result >= 0)
                return 0;
        }
        delete created;
        *object = 0;
        return result;
    }
    *object = 0;
    return 0x8007000e;
}
