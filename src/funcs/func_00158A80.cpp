/* sym: ??0Object_001E14D8@@QAE@XZ = 0x001589D0 */
/* sym: ?func_00157F00_1@Object_001E1508@@UAGJPBXPAPAX@Z = 0x0015B5C0 */
/* sym: ?func_0014D080_6@Object_001E1508@@UAGKXZ = 0x00158C80 */
/* sym: ?func_00158A50@Object_001E1508@@UAGJK@Z = 0x0015B570 */
/* sym: ?func_00158A60@Object_001E1508@@UAGJKKK@Z = 0x0015B400 */
/* sym: ?func_00157F20_3@Object_001E1508@@UAGXK@Z = 0x0015B460 */
/* sym: ?func_00157F20_4@Object_001E1508@@UAGXK@Z = 0x0015B4E0 */
/* sym: ?func_00157F00_1@Object_001E1538@@UAGJPBXPAPAX@Z = 0x0015B9A0 */
/* sym: ?func_0014D080_6@Object_001E1538@@UAGKXZ = 0x00158C80 */
/* sym: ?func_00158A50@Object_001E1538@@UAGJK@Z = 0x0015B8B0 */
/* sym: ?func_00158A60@Object_001E1538@@UAGJKKK@Z = 0x0015BC20 */
/* sym: ?func_001587F0@Object_001E1538@@UAGXMK@Z = 0x0015B630 */
/* sym: ?func_00157F20_3@Object_001E1538@@UAGXK@Z = 0x0015B650 */
/* sym: ?func_00157F20_4@Object_001E1538@@UAGXK@Z = 0x0015B6E0 */
/* sym: ?func_00157F00_1@Object_001E1568@@UAGJPBXPAPAX@Z = 0x0015BDF0 */
/* sym: ?func_0014D080_6@Object_001E1568@@UAGKXZ = 0x00158C80 */
/* sym: ?func_001588F0@Object_001E1568@@UAGJXZ = 0x00150FD0 */
/* sym: ?func_00158960@Object_001E1568@@UAGJXZ = 0x0014D080 */
/* sym: ?func_00158A50@Object_001E1568@@UAGJK@Z = 0x001504B0 */
/* sym: ?func_00158A60@Object_001E1568@@UAGJKKK@Z = 0x0015C040 */
/* sym: ?func_00157F20_3@Object_001E1568@@UAGXK@Z = 0x0015BCD0 */
/* sym: ?func_00157F20_4@Object_001E1568@@UAGXK@Z = 0x0015BD60 */
struct Guid;
extern const Guid data_001E16E8;
extern const Guid data_001E16D8;
extern const Guid data_001E16C8;

// The base of the classes whose tables are at 0x1E1508, 0x1E1538 and 0x1E1568 (0x128 bytes; constructor
// 0x1589D0).
struct Object_001E14D8 {
    virtual long __stdcall func_00157F00_1(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded
    virtual unsigned long __stdcall func_00158A30();  // slot 1
    virtual unsigned long __stdcall func_0014D080_6();  // slot 2: returns 0, folded
    virtual long __stdcall func_001588F0();  // slot 3
    virtual long __stdcall func_00158960();  // slot 4
    virtual long __stdcall func_00158A50(unsigned long value);  // slot 5
    virtual long __stdcall func_00158A60(unsigned long first, unsigned long second, unsigned long third);  // slot 6
    virtual void __stdcall func_00158780();  // slot 7
    virtual void __stdcall func_001587F0(float value, unsigned long unused);  // slot 8
    virtual void __stdcall func_00158810(const unsigned long *values, unsigned long second);  // slot 9
    virtual void __stdcall func_00157F20_3(unsigned long value);  // slot 10: does nothing, folded
    virtual void __stdcall func_00157F20_4(unsigned long value);  // slot 11: the same folded function

    Object_001E14D8() throw();
    ~Object_001E14D8() {}

    long __stdcall func_0015B600(unsigned long first, unsigned long second);

    unsigned long words[0x49];
};

// Kind 0 (0x128 bytes).
struct Object_001E1508 : Object_001E14D8 {
    virtual long __stdcall func_00157F00_1(const void *iid, void **object);  // slot 0, at 0x15B5C0
    virtual unsigned long __stdcall func_0014D080_6();  // slot 2, at 0x158C80: Release, folded across the kinds
    virtual long __stdcall func_00158A50(unsigned long value);  // slot 5, at 0x15B570
    virtual long __stdcall func_00158A60(unsigned long first, unsigned long second, unsigned long third);  // slot 6
    virtual void __stdcall func_00157F20_3(unsigned long value);  // slot 10, at 0x15B460
    virtual void __stdcall func_00157F20_4(unsigned long value);  // slot 11, at 0x15B4E0

    Object_001E1508() {}
    ~Object_001E1508() {}
};

// Kind 1 (0x12C bytes).
struct Object_001E1538 : Object_001E14D8 {
    virtual long __stdcall func_00157F00_1(const void *iid, void **object);  // slot 0, at 0x15B9A0
    virtual unsigned long __stdcall func_0014D080_6();  // slot 2, at 0x158C80
    virtual long __stdcall func_00158A50(unsigned long value);  // slot 5, at 0x15B8B0
    virtual long __stdcall func_00158A60(unsigned long first, unsigned long second, unsigned long third);  // slot 6
    virtual void __stdcall func_001587F0(float value, unsigned long unused);  // slot 8, at 0x15B630
    virtual void __stdcall func_00157F20_3(unsigned long value);  // slot 10, at 0x15B650
    virtual void __stdcall func_00157F20_4(unsigned long value);  // slot 11, at 0x15B6E0

    Object_001E1538() : value_128(0) {}
    ~Object_001E1538() {}

    unsigned long value_128;
};

// Kind 2 (0x128 bytes).
struct Object_001E1568 : Object_001E14D8 {
    virtual long __stdcall func_00157F00_1(const void *iid, void **object);  // slot 0, at 0x15BDF0
    virtual unsigned long __stdcall func_0014D080_6();  // slot 2, at 0x158C80
    virtual long __stdcall func_001588F0();  // slot 3, at 0x150FD0 (folded)
    virtual long __stdcall func_00158960();  // slot 4, at 0x14D080 (folded)
    virtual long __stdcall func_00158A50(unsigned long value);  // slot 5, at 0x1504B0 (folded)
    virtual long __stdcall func_00158A60(unsigned long first, unsigned long second, unsigned long third);  // slot 6
    virtual void __stdcall func_00157F20_3(unsigned long value);  // slot 10, at 0x15BCD0
    virtual void __stdcall func_00157F20_4(unsigned long value);  // slot 11, at 0x15BD60

    Object_001E1568() {}
    ~Object_001E1568() {}
};

// The factory object whose table is at 0x1E13F0.
struct Object_001E13F0 {
    virtual long __stdcall func_00158A80(unsigned long first, unsigned long second, void **object);  // slot 7
};

// Creates the object of the kind in the low four bits of the second argument (0, 1 or 2), gets its interface and
// sets it up (func_0015B600) with both arguments; *object is the result or null. E_INVALIDARG for another kind,
// E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E13F0::func_00158A80(unsigned long first, unsigned long second, void **object)
{
    switch (second & 0xf) {
    case 0: {
        Object_001E1508 *created = new Object_001E1508;
        if (created) {
            long result = created->func_00157F00_1(&data_001E16E8, (void **)&created);
            if (result >= 0) {
                result = created->func_0015B600(first, second);
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
        Object_001E1538 *created = new Object_001E1538;
        if (created) {
            long result = created->func_00157F00_1(&data_001E16D8, (void **)&created);
            if (result >= 0) {
                result = created->func_0015B600(first, second);
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
    case 2: {
        Object_001E1568 *created = new Object_001E1568;
        if (created) {
            long result = created->func_00157F00_1(&data_001E16C8, (void **)&created);
            if (result >= 0) {
                result = created->func_0015B600(first, second);
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
