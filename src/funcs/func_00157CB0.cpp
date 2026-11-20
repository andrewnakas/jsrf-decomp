struct Guid;
extern const Guid data_001E16B8;

// The class whose table is at 0x1E144C (11 slots, 0x28 bytes; Release 0x157DB0, created by 0x157CB0).
struct Object_001E144C {
    virtual long __stdcall func_00157D70(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_00157CA0();  // slot 1
    virtual unsigned long __stdcall func_00157DB0();  // slot 2
    virtual long __stdcall func_0015A910();  // slot 3
    virtual unsigned long __stdcall func_0015A940();  // slot 4
    virtual long __stdcall func_0015A880(unsigned long first, unsigned long second);  // slot 5
    virtual long __stdcall func_0015A560(unsigned long first, unsigned long second, unsigned long third);  // slot 6
    virtual long __stdcall func_00157C50();  // slot 7
    virtual void __stdcall func_00157BF0(int index, float value);  // slot 8
    virtual long __stdcall func_0015A960(unsigned long first, unsigned long second);  // slot 9
    virtual long __stdcall func_0015A660(int position);  // slot 10

    Object_001E144C()
        : value_04(0), value_08(0), value_0C(0), value_10(0), value_14(0), value_18(0), value_1C(0), value_20(0),
          references(0)
    {
    }
    ~Object_001E144C() {}

    long __stdcall func_001579D0(unsigned long first, unsigned long second);

    unsigned long value_04;
    unsigned long value_08;
    unsigned long value_0C;
    unsigned long value_10;
    unsigned long value_14;
    unsigned long value_18;
    unsigned long value_1C;
    unsigned long value_20;
    unsigned long references;
};

// The factory object whose table is at 0x1E13F0.
struct Object_001E13F0 {
    virtual long __stdcall func_00157CB0(unsigned long first, unsigned long second, void **object);  // slot 9
};

// Creates an Object_001E144C, gets its interface data_001E16B8 and sets it up (func_001579D0) with the two
// arguments; *object is the result or null. E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E13F0::func_00157CB0(unsigned long first, unsigned long second, void **object)
{
    Object_001E144C *created = new Object_001E144C;
    if (created) {
        long result = created->func_00157D70(&data_001E16B8, (void **)&created);
        if (result >= 0) {
            result = created->func_001579D0(first, second);
            if (result >= 0) {
                *object = created;
                return 0;
            }
        }
        delete created;
        *object = 0;
        return result;
    }
    *object = 0;
    return 0x8007000e;
}
