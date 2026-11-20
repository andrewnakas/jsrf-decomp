struct Guid;
extern const Guid data_001E13D0;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots).
struct Object_001E0F00 {
    virtual long __stdcall func_001536E0(unsigned long argument1, void **object);  // slot 57
};

// The class whose table is at 0x1E12F8 (12 slots, 8 bytes; Release 0x153670, created by 0x1536E0).
struct Object_001E12F8 {
    virtual long __stdcall func_00153300(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0();  // slot 1: AddRef
    virtual unsigned long __stdcall func_00153670();  // slot 2: Release
    virtual long __stdcall func_001533D0(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 3
    virtual long __stdcall func_00152E30(int index);  // slot 4
    virtual long __stdcall func_00153520(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 5
    virtual long __stdcall func_00152E90(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 6
    virtual long __stdcall func_001530F0(unsigned long argument1, unsigned long argument2);  // slot 7
    virtual long __stdcall func_00152FE0(unsigned long argument1);  // slot 8
    virtual long __stdcall func_001531E0();  // slot 9
    virtual long __stdcall func_00153240(unsigned long value);  // slot 10
    virtual long __stdcall func_001532A0();  // slot 11

    Object_001E12F8() : references(0) {}
    ~Object_001E12F8() {}

    long __stdcall func_00153340(unsigned int count);

    unsigned long references;
};

// Creates an Object_001E12F8, gets its interface data_001E13D0 into *object and sets it up (func_00153340) with
// the argument. E_OUTOFMEMORY when the allocation fails; on a failure *object is null.
long __stdcall Object_001E0F00::func_001536E0(unsigned long argument1, void **object)
{
    Object_001E12F8 *created = new Object_001E12F8;
    if (created) {
        long result = created->func_00153300(&data_001E13D0, object);
        if (result >= 0) {
            result = created->func_00153340(argument1);
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
