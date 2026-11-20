struct Record;

struct Guid;
extern const Guid data_001E1718;

// The class whose table is at 0x1E1610 (11 slots, 0x20 bytes; Release 0x159420, created by 0x159450).
struct Object_001E1610 {
    virtual long __stdcall func_00159180(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_00159170();  // slot 1
    virtual unsigned long __stdcall func_00159420();  // slot 2
    virtual long __stdcall func_00159080();  // slot 3
    virtual unsigned long __stdcall func_001590B0();  // slot 4
    virtual long __stdcall func_0015C5D0(unsigned long value);  // slot 5
    virtual long __stdcall func_0015C600(unsigned long first, unsigned long second, unsigned long third);  // slot 6
    virtual long __stdcall func_001590D0();  // slot 7
    virtual long __stdcall func_00159330(const Record *records, unsigned int count);  // slot 8
    virtual long __stdcall func_0015C670(unsigned long value);  // slot 9
    virtual long __stdcall func_0015C6E0(int position);  // slot 10

    Object_001E1610()
        : voice(0), value_08(0), value_0C(0), value_10(0), value_14(0), position(0), references(0)
    {
    }
    ~Object_001E1610() {}

    long __stdcall func_001591C0(unsigned long first, unsigned long second, unsigned long third);

    void *voice;
    unsigned long value_08;
    unsigned long value_0C;
    unsigned long value_10;
    unsigned long value_14;
    int position;
    unsigned long references;
};

// The factory object whose table is at 0x1E13F0.
struct Object_001E13F0 {
    virtual long __stdcall func_00159450(unsigned long first, unsigned long second, unsigned long third,
                                         void **object);  // slot 5
};

// Creates an Object_001E1610, gets its interface data_001E1718 and sets it up (func_001591C0) with the three
// arguments; *object is the result or null. E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E13F0::func_00159450(unsigned long first, unsigned long second, unsigned long third,
                                              void **object)
{
    Object_001E1610 *created = new Object_001E1610;
    if (created) {
        long result = created->func_00159180(&data_001E1718, (void **)&created);
        if (result >= 0) {
            result = created->func_001591C0(first, second, third);
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
