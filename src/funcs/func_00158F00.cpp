/* sym: ?func_00157F00_2@Object_001E15C0@@UAGJPBXPAPAX@Z = 0x0015C120 */
/* sym: ?func_0014D080_7@Object_001E15C0@@UAGKXZ = 0x00159050 */
/* sym: ?func_00157F20_5@Object_001E15C0@@UAGXK@Z = 0x0015C0C0 */
/* sym: ?func_00157F00_2@Object_001E15E8@@UAGJPBXPAPAX@Z = 0x0015C240 */
/* sym: ?func_0014D080_7@Object_001E15E8@@UAGKXZ = 0x00159050 */
/* sym: ?func_00157F20_5@Object_001E15E8@@UAGXK@Z = 0x0015C1C0 */
struct Guid;
struct Vector4;
struct Buffer;
extern const Guid data_001E1708;
extern const Guid data_001E16F8;

// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual long __stdcall func_00157F00_2(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded
    virtual unsigned long __stdcall func_00158EE0();  // slot 1
    virtual unsigned long __stdcall func_0014D080_7();  // slot 2: returns 0, folded
    virtual long __stdcall func_00158D70();  // slot 3
    virtual unsigned long __stdcall func_00158D90();  // slot 4
    virtual long __stdcall func_00158DB0(const Vector4 *value);  // slot 5
    virtual long __stdcall func_00158E30(const void *source, unsigned int count, unsigned int stride);  // slot 6
    virtual void __stdcall func_00158E80();  // slot 7
    virtual void __stdcall func_00158ED0(float value);  // slot 8
    virtual void __stdcall func_00157F20_5(unsigned long value);  // slot 9: does nothing, folded

    Object_001E1598() : buffer(0), value_08(0), value(1.0f), position(0), value_14(0), references(0) {}
    ~Object_001E1598() {}

    long __stdcall func_0015C160(unsigned long first, unsigned long second);

    Buffer *buffer;
    unsigned long value_08;
    float value;
    unsigned long position;
    unsigned long value_14;
    unsigned long references;
};

// Kind 0 (0x1C bytes).
struct Object_001E15C0 : Object_001E1598 {
    virtual long __stdcall func_00157F00_2(const void *iid, void **object);  // slot 0, at 0x15C120
    virtual unsigned long __stdcall func_0014D080_7();  // slot 2, at 0x159050: Release, folded with 0x1E15E8's
    virtual void __stdcall func_00157F20_5(unsigned long value);  // slot 9, at 0x15C0C0

    ~Object_001E15C0() {}
};

// Kind 1 (0x1C bytes).
struct Object_001E15E8 : Object_001E1598 {
    virtual long __stdcall func_00157F00_2(const void *iid, void **object);  // slot 0, at 0x15C240
    virtual unsigned long __stdcall func_0014D080_7();  // slot 2, at 0x159050: Release, folded with 0x1E15C0's
    virtual void __stdcall func_00157F20_5(unsigned long value);  // slot 9, at 0x15C1C0

    ~Object_001E15E8() {}
};

// The factory object whose table is at 0x1E13F0.
struct Object_001E13F0 {
    virtual long __stdcall func_00158F00(unsigned long first, unsigned long second, void **object);  // slot 6
};

// Creates the object of the kind in the low four bits of the second argument (0 or 1), gets its interface and sets
// it up (func_0015C160) with both arguments; *object is the result or null. E_INVALIDARG for another kind,
// E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E13F0::func_00158F00(unsigned long first, unsigned long second, void **object)
{
    switch (second & 0xf) {
    case 0: {
        Object_001E15C0 *created = new Object_001E15C0;
        if (created) {
            long result = created->func_00157F00_2(&data_001E1708, (void **)&created);
            if (result >= 0) {
                result = created->func_0015C160(first, second);
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
    case 1: {
        Object_001E15E8 *created = new Object_001E15E8;
        if (created) {
            long result = created->func_00157F00_2(&data_001E16F8, (void **)&created);
            if (result >= 0) {
                result = created->func_0015C160(first, second);
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
    default:
        return 0x80070057;
    }
}
