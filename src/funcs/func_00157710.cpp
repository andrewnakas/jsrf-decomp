extern "C" void *memset(void *destination, int value, unsigned int size);

struct Guid;
extern const Guid data_001E16A8;

// The class whose table is at 0x1E141C (12 slots, 0x1040 bytes; constructor 0x157680, Release 0x1579A0, created
// by 0x157710).
struct Object_001E141C {
    virtual long __stdcall func_001577C0(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001576F0();  // slot 1
    virtual unsigned long __stdcall func_001579A0();  // slot 2
    virtual long __stdcall func_00157800(unsigned long first, unsigned long second, unsigned long third);  // slot 3
    virtual void __stdcall func_00157960();  // slot 4
    virtual long __stdcall func_00157100(unsigned long first, unsigned long second);  // slot 5
    virtual long __stdcall func_001571E0(unsigned long first, unsigned long second);  // slot 6
    virtual long __stdcall func_001572D0();  // slot 7
    virtual long __stdcall func_00157300();  // slot 8
    virtual long __stdcall func_0015A1C0(unsigned long first, unsigned long second, unsigned long third);  // slot 9
    virtual long __stdcall func_00157320(unsigned long first, unsigned long second);  // slot 10
    virtual long __stdcall func_001574C0(unsigned long first, unsigned long second, unsigned long third);  // slot 11

    Object_001E141C()
    {
        value_1014 = 0;
        value_1018 = 0;
        value_101C = 0;
        value_1020 = 1.0f;
        memset(buffer, 0, sizeof(buffer));
        aligned = (unsigned long *)(((unsigned long)buffer + 15) & ~15);
        value_1028[0] = 0;
        value_1028[1] = 0;
        value_1028[2] = 0;
        value_1028[3] = 0;
        value_1028[4] = 0;
        references = 0;
    }
    ~Object_001E141C() {}

    long __stdcall func_00156E70(unsigned long first, unsigned long second, unsigned long third);

    unsigned long buffer[0x404];
    unsigned long value_1014;
    unsigned long value_1018;
    unsigned long value_101C;
    float value_1020;
    unsigned long *aligned;
    unsigned long value_1028[5];
    unsigned long references;
};

// The factory object whose table is at 0x1E13F0.
struct Object_001E13F0 {
    virtual long __stdcall func_00157710(unsigned long first, unsigned long second, unsigned long third,
                                         void **object);  // slot 10
};

// Creates an Object_001E141C, gets its interface data_001E16A8 and sets it up (func_00156E70) with the three
// arguments; *object is the result or null. E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E13F0::func_00157710(unsigned long first, unsigned long second, unsigned long third,
                                              void **object)
{
    Object_001E141C *created = new Object_001E141C;
    if (created) {
        long result = created->func_001577C0(&data_001E16A8, (void **)&created);
        if (result >= 0) {
            result = created->func_00156E70(first, second, third);
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
