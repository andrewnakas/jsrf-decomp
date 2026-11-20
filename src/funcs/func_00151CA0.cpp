struct Guid;
extern const Guid data_001E1340;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots).
struct Object_001E0F00 {
    virtual long __stdcall func_00151CA0(unsigned long argument1, unsigned long argument2, unsigned long argument3,
                                         void **object);  // slot 61
};

// A class whose table is at 0x1E1248 (9 slots, 0x24 bytes; Release 0x151C40, created by 0x151CA0).
struct Object_001E1248 {
    virtual long __stdcall func_00151AC0(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014D4A0_1();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_00151C40();  // slot 2
    virtual void __stdcall func_00151820(int level, unsigned long color);  // slot 3
    virtual long __stdcall func_00151840(unsigned long x, unsigned long y, const char *text);  // slot 4
    virtual long __stdcall func_001519D0(unsigned long x, unsigned long y, int number);  // slot 5
    virtual long __stdcall func_00151A00(unsigned long x, unsigned long y, unsigned long value);  // slot 6
    virtual long __stdcall func_00151A30(unsigned long x, unsigned long y, float value);  // slot 7
    virtual long func_00151A90(unsigned long x, unsigned long y, const char *format, ...);  // slot 8

    Object_001E1248()
    {
        color[0] = 255.0f;
        color[1] = 255.0f;
        color[2] = 255.0f;
        color[3] = 1.0f;
        memory = 0;
        index = 0;
        scale = 1.0f;
        references = 0;
    }
    ~Object_001E1248() {}

    long func_00151B00(unsigned long argument1, unsigned long argument2, unsigned long argument3);

    float color[4];
    void *memory;
    unsigned int index;
    float scale;
    unsigned long references;
};

// Creates an Object_001E1248 (white, scale 1), gets its interface data_001E1340 and sets it up (func_00151B00)
// with the three arguments; *object is the result or null. E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E0F00::func_00151CA0(unsigned long argument1, unsigned long argument2,
                                              unsigned long argument3, void **object)
{
    Object_001E1248 *created = new Object_001E1248;
    if (created) {
        long result = created->func_00151AC0(&data_001E1340, (void **)&created);
        if (result >= 0) {
            result = created->func_00151B00(argument1, argument2, argument3);
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
