struct Guid;
extern const Guid data_001E1390;

// The class whose table is at 0x1E1328 (6 slots, 0xC bytes; Release 0x153850, created by 0x1539B0).
struct Object_001E1328 {
    virtual long __stdcall func_001537C0(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001537B0();  // slot 1
    virtual unsigned long __stdcall func_00153850();  // slot 2
    virtual long __stdcall func_00153760();  // slot 3
    virtual void __stdcall func_00153780();  // slot 4
    virtual long __stdcall func_00153790(unsigned long first, unsigned long second, unsigned long third);  // slot 5

    Object_001E1328() : object(0), references(0) {}
    ~Object_001E1328() {}

    long func_00153890(unsigned long argument1, unsigned long argument2);

    void *object;
    unsigned long references;
};

// The Direct3D device wrapper: table 0x1E0F00 (121 slots).
struct Object_001E0F00 {
    virtual long __stdcall func_001539B0(unsigned long argument1, unsigned long argument2,
                                         void **object);  // slot 56

    char unknown_04[0x8C];
    void *value_90;
};

// Creates an Object_001E1328, gets its interface data_001E1390 and sets it up (func_00153890) with the two
// arguments; *object is the result or null. S_FALSE when the value at +0x90 is gone by then, E_NOTIMPL without
// it, E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E0F00::func_001539B0(unsigned long argument1, unsigned long argument2, void **object)
{
    if (value_90) {
        Object_001E1328 *created = new Object_001E1328;
        if (created) {
            long result = created->func_001537C0(&data_001E1390, (void **)&created);
            if (result >= 0) {
                result = created->func_00153890(argument1, argument2);
                if (result >= 0) {
                    *object = created;
                    return value_90 ? 0 : 1;
                }
            }
            delete created;
            *object = 0;
            return result;
        }
        *object = 0;
        return 0x8007000e;
    }
    return 0x80004001;
}
