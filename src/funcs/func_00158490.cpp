/* sym: ?func_00157F00@Object_001E1498@@UAGJPBXPAPAX@Z = 0x00157DE0 */
/* sym: ?func_0014D080_5@Object_001E1498@@UAGKXZ = 0x00158430 */
/* sym: ?func_00157F10@Object_001E1498@@UAGJK@Z = 0x00158030 */
/* sym: ?func_00157F20@Object_001E1498@@UAGXK@Z = 0x001583F0 */
/* sym: ?func_00157F30@Object_001E1498@@UAGXKK@Z = 0x0015AD10 */
/* sym: ?func_00157F20_1@Object_001E1498@@UAGXK@Z = 0x0015AE70 */
/* sym: ?func_00157F20_2@Object_001E1498@@UAGXK@Z = 0x0015AE20 */
/* sym: ?func_00157F00@Object_001E14B8@@UAGJPBXPAPAX@Z = 0x0015B010 */
/* sym: ?func_0014D080_5@Object_001E14B8@@UAGKXZ = 0x00158460 */
/* sym: ?func_00157F10@Object_001E14B8@@UAGJK@Z = 0x0015B0B0 */
/* sym: ?func_00157F20@Object_001E14B8@@UAGXK@Z = 0x0015B210 */
/* sym: ?func_00157F30@Object_001E14B8@@UAGXKK@Z = 0x0015B240 */
/* sym: ?func_00157F20_2@Object_001E14B8@@UAGXK@Z = 0x0015B2E0 */
struct Guid;
extern const Guid data_001E1738;
extern const Guid data_001E1728;

// The base of the classes whose tables are at 0x1E1498 and 0x1E14B8 (created by 0x158490): its table at 0x1E1478
// (8 slots) is the default every override replaces.
struct Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0_2();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_0014D080_5();  // slot 2: returns 0, folded
    virtual long __stdcall func_00157F10(unsigned long value);  // slot 3
    virtual void __stdcall func_00157F20(unsigned long value);  // slot 4
    virtual void __stdcall func_00157F30(unsigned long first, unsigned long second);  // slot 5
    virtual void __stdcall func_00157F20_1(unsigned long value);  // slot 6: the same folded function
    virtual void __stdcall func_00157F20_2(unsigned long value);  // slot 7: the same folded function

    Object_001E1478() : references(0) {}
    ~Object_001E1478() {}

    unsigned long references;
};

// Kind 0 (0x14 bytes): overrides every slot but the AddRef.
struct Object_001E1498 : Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0, at 0x157DE0
    virtual unsigned long __stdcall func_0014D080_5();  // slot 2, at 0x158430
    virtual long __stdcall func_00157F10(unsigned long value);  // slot 3, at 0x158030
    virtual void __stdcall func_00157F20(unsigned long value);  // slot 4, at 0x1583F0
    virtual void __stdcall func_00157F30(unsigned long first, unsigned long second);  // slot 5, at 0x15AD10
    virtual void __stdcall func_00157F20_1(unsigned long value);  // slot 6, at 0x15AE70
    virtual void __stdcall func_00157F20_2(unsigned long value);  // slot 7, at 0x15AE20

    Object_001E1498() : value_08(0), value_0C(0), value_10(0) {}
    ~Object_001E1498() {}

    long __stdcall func_00157F50(unsigned int count, unsigned long flags);

    unsigned long value_08;
    unsigned long value_0C;
    unsigned long value_10;
};

// Kind 1 (0x10 bytes): keeps the default slot 6.
struct Object_001E14B8 : Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0, at 0x15B010
    virtual unsigned long __stdcall func_0014D080_5();  // slot 2, at 0x158460
    virtual long __stdcall func_00157F10(unsigned long value);  // slot 3, at 0x15B0B0
    virtual void __stdcall func_00157F20(unsigned long value);  // slot 4, at 0x15B210
    virtual void __stdcall func_00157F30(unsigned long first, unsigned long second);  // slot 5, at 0x15B240
    virtual void __stdcall func_00157F20_2(unsigned long value);  // slot 7, at 0x15B2E0

    Object_001E14B8() : value_08(0), value_0C(0) {}
    ~Object_001E14B8() {}

    long __stdcall func_0015B300(unsigned int count, unsigned long flags);

    unsigned long value_08;
    unsigned long value_0C;
};

// The factory object whose table is at 0x1E13F0.
struct Object_001E13F0 {
    virtual long __stdcall func_00158490(unsigned long first, unsigned long second, void **object);  // slot 8
};

// Creates the object of the kind (0 or 1), gets its interface and sets it up for the count; *object is the result
// or null. E_INVALIDARG for another kind, E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E13F0::func_00158490(unsigned long first, unsigned long second, void **object)
{
    if (second == 0) {
        Object_001E1498 *created = new Object_001E1498;
        if (created) {
            long result = created->func_00157F00(&data_001E1738, (void **)&created);
            if (result >= 0) {
                result = created->func_00157F50(first, 0);
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
    } else if (second == 1) {
        Object_001E14B8 *created = new Object_001E14B8;
        if (created) {
            long result = created->func_00157F00(&data_001E1728, (void **)&created);
            if (result >= 0) {
                result = created->func_0015B300(first, 1);
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
    } else
        return 0x80070057;
}
