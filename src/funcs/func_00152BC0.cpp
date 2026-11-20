struct Guid;
struct Rect;
extern const Guid data_001E1380;
extern const Guid data_001E1370;
extern const Guid data_001E1360;

// What slot 3 of the classes below copies out: the three values at +8.
struct Info {
    unsigned long values[3];
};

// The Direct3D device wrapper: table 0x1E0F00 (121 slots).
struct Object_001E0F00 {
    virtual long __stdcall func_00152BC0(unsigned long argument1, unsigned long argument2, unsigned long argument3,
                                         unsigned long kind, void **object);  // slot 58
};

// The base of the classes whose tables are at 0x1E1290 (destructor 0x152690), 0x1E1298, 0x1E12B8 and 0x1E12D8
// (created by 0x152BC0); all four share this QueryInterface.
struct Object_001E1290 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014E1F0_1();  // slot 1: AddRef, folded

    Object_001E1290() : object(0), value_08(0), value_0C(0), value_10(-1), references(0) {}
    ~Object_001E1290() {}

    void *object;
    unsigned long value_08;
    unsigned long value_0C;
    long value_10;
    unsigned long references;
};

// Kind 1 (0x18 bytes).
struct Object_001E1298 : Object_001E1290 {
    virtual unsigned long __stdcall func_00152AE0();  // slot 2
    virtual long __stdcall func_001526A0(Info *out);  // slot 3, folded with the other two
    virtual long __stdcall func_00152740(unsigned long *second, unsigned long *first, unsigned long unused);  // slot 4
    virtual void __stdcall func_00011C80_5();  // slot 5: does nothing, folded
    virtual long __stdcall func_00152780(void *first, void *second, const Rect *rect);  // slot 6
    virtual long __stdcall func_001525D0(unsigned long value);  // slot 7

    ~Object_001E1298() {}

    long func_001526E0(unsigned long argument1, unsigned long argument2, unsigned long argument3);
};

// Kind 2 (0x28 bytes).
struct Object_001E12B8 : Object_001E1290 {
    virtual unsigned long __stdcall func_00152B30();  // slot 2
    virtual long __stdcall func_001526A0_1(Info *out);  // slot 3, folded
    virtual long __stdcall func_00152960(unsigned long *second, unsigned long *first, unsigned long flags);  // slot 4
    virtual void __stdcall func_00152A00();  // slot 5
    virtual long __stdcall func_001526D0_4(void *argument1, void *argument2, void *argument3);  // slot 6: E_NOTIMPL
    virtual long __stdcall func_00152630(unsigned long value);  // slot 7

    Object_001E12B8() : value_18(0), value_1C(-1), value_20(0), value_24(0) {}
    ~Object_001E12B8() {}

    long func_00152810(unsigned long argument);

    unsigned long value_18;
    long value_1C;
    unsigned long value_20;
    unsigned long value_24;
};

// Kind 3 (0x18 bytes).
struct Object_001E12D8 : Object_001E1290 {
    virtual unsigned long __stdcall func_00152B60();  // slot 2
    virtual long __stdcall func_001526A0_2(Info *out);  // slot 3, folded
    virtual long __stdcall func_001526D0_5(void *argument1, void *argument2, void *argument3);  // slot 4: E_NOTIMPL
    virtual void __stdcall func_00011C80_6();  // slot 5: does nothing, folded
    virtual long __stdcall func_001526D0_6(void *argument1, void *argument2, void *argument3);  // slot 6: E_NOTIMPL
    virtual long __stdcall func_001504B0_5(unsigned long value);  // slot 7: E_NOTIMPL

    ~Object_001E12D8() {}

    long func_00152A60();
};

// Creates the object of the kind (1 to 3), gets its interface and sets it up with the arguments it takes; *object
// is the result or null. E_NOINTERFACE for another kind, E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E0F00::func_00152BC0(unsigned long argument1, unsigned long argument2,
                                              unsigned long argument3, unsigned long kind, void **object)
{
    long result = 0x80004002;
    if (kind == 1) {
        Object_001E1298 *created = new Object_001E1298;
        if (created) {
            result = created->func_00152360(&data_001E1380, (void **)&created);
            if (result >= 0) {
                result = created->func_001526E0(argument1, argument2, argument3);
                if (result >= 0) {
                    *object = created;
                    return 0;
                }
            }
            delete created;
        } else
            result = 0x8007000e;
    } else if (kind == 2) {
        Object_001E12B8 *created = new Object_001E12B8;
        if (created) {
            result = created->func_00152360(&data_001E1370, (void **)&created);
            if (result >= 0) {
                result = created->func_00152810(argument3);
                if (result >= 0) {
                    *object = created;
                    return 0;
                }
            }
            delete created;
        } else
            result = 0x8007000e;
    } else if (kind == 3) {
        Object_001E12D8 *created = new Object_001E12D8;
        if (created) {
            result = created->func_00152360(&data_001E1360, (void **)&created);
            if (result >= 0) {
                result = created->func_00152A60();
                if (result >= 0) {
                    *object = created;
                    return 0;
                }
            }
            delete created;
        } else
            result = 0x8007000e;
    }
    *object = 0;
    return result;
}
