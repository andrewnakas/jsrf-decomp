/* sym: ?func_0014D490@Object_001E1150@@UAGJPBXPAPAX@Z = 0x0014D410 */
/* sym: ?func_0014D080@Object_001E1150@@UAGKXZ = 0x0014D770 */
struct Guid;
extern const Guid data_001E13C0;

// The device's statistics, a base of the device at +4.
struct Stats {
    unsigned long unknown_00[2];
    unsigned int primitives;
    unsigned int draws;
};

extern Stats *data_002650EC;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), 0xE4 bytes; its statistics are at +4.
struct Object_001E0F00 : Stats {
    virtual long __stdcall func_0014D800(unsigned long argument1, unsigned long argument2, unsigned long argument3,
                                         unsigned long argument4, void **object);  // slot 54
};

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014D4A0();  // slot 1
    virtual unsigned long __stdcall func_0014D080();  // slot 2: returns 0
    virtual long __stdcall func_00155E50(int kind);  // slot 3
    virtual long __stdcall func_00155E30(unsigned long first, unsigned long second);  // slot 4
    virtual unsigned long __stdcall func_0014D080_1();  // slot 5: the same folded function
    virtual long __stdcall func_00156030(unsigned long *value, unsigned long unused);  // slot 6
    virtual unsigned long __stdcall func_0014D080_2();  // slot 7: the same folded function
    virtual long __stdcall func_00155B20(unsigned long stage);  // slot 8
    virtual long __stdcall func_00155B40();  // slot 9
    virtual long __stdcall func_00155B80();  // slot 10
    virtual long __stdcall func_00155BC0();  // slot 11
    virtual long __stdcall func_00155EF0();  // slot 12
    virtual long __stdcall func_00155C00(unsigned int count);  // slot 13
    virtual long __stdcall func_00155C30(unsigned int count);  // slot 14
    virtual long __stdcall func_00155F40(unsigned int count, unsigned int start);  // slot 15
    virtual long __stdcall func_00155CE0();  // slot 16
    virtual long __stdcall func_00155D20();  // slot 17
    virtual long __stdcall func_00155D60();  // slot 18
    virtual long __stdcall func_00155DA0(unsigned int count);  // slot 19
    virtual long __stdcall func_00155DD0(unsigned int count);  // slot 20
    virtual long __stdcall func_00155E00(unsigned int count);  // slot 21
    virtual long __stdcall func_00155F90();  // slot 22
    virtual long __stdcall func_00155FE0(unsigned int count, unsigned int start);  // slot 23
    virtual long __stdcall func_00155C70();  // slot 24
    virtual long __stdcall func_00155CB0(unsigned int count);  // slot 25


    Object_001E10E8() : object(0), resource(0), shader(0), extra(0), vertexCount(0), value_18(0), value_1C(0),
                        references(0) {}
    ~Object_001E10E8() {}

    void *object;
    void *resource;
    unsigned long shader;
    unsigned long extra;
    unsigned int vertexCount;
    unsigned long value_18;
    unsigned long value_1C;
    unsigned long references;
};

// The class whose table is at 0x1E1150 (0x24 bytes, created by 0x14D800): constructing one makes data_002650EC point at the device's
// statistics.
struct Object_001E1150 : Object_001E10E8 {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0, at 0x14D410
    virtual unsigned long __stdcall func_0014D080();  // slot 2, at 0x14D770

    Object_001E1150(Object_001E0F00 *device)
    {
        if (device)
            data_002650EC = device;
    }
    ~Object_001E1150() {}

    long func_0014D4C0(unsigned long argument1, unsigned long argument2, unsigned long argument3,
                       unsigned long argument4);
};

// Creates an Object_001E1150, gets its interface data_001E13C0 and sets it up (func_0014D4C0) with the four
// arguments; *object is the result or null. E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E0F00::func_0014D800(unsigned long argument1, unsigned long argument2,
                                              unsigned long argument3, unsigned long argument4, void **object)
{
    Object_001E1150 *created = new Object_001E1150(this);
    if (created) {
        long result = created->func_0014D490(&data_001E13C0, (void **)&created);
        if (result >= 0) {
            result = created->func_0014D4C0(argument1, argument2, argument3, argument4);
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
