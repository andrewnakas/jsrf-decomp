struct Guid;
extern const Guid data_001E13A0;

// A class whose table is at 0x1E1220 (6 slots, 0x18 bytes): a vertex shader.
struct Object_001E1220 {
    virtual long __stdcall func_0014E200(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014E1F0();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_0014E2B0();  // slot 2
    virtual long __stdcall func_0014D9F0();  // slot 3
    virtual void __stdcall func_0014DA20();  // slot 4
    virtual long __stdcall func_0014DB70(unsigned long first, unsigned long second, unsigned long third);  // slot 5

    Object_001E1220() : shader(0), format(0), value_0C(0), count(1), references(0) {}
    ~Object_001E1220() {}

    long func_0014E2F0(unsigned long format, const unsigned long *function, unsigned long flags);

    unsigned long shader;
    unsigned long format;
    unsigned long value_0C;
    unsigned long count;
    unsigned long references;
};

// The Direct3D device wrapper: table 0x1E0F00 (121 slots).
struct Object_001E0F00 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual long __stdcall func_0014E430(unsigned long argument1, unsigned long argument2, unsigned long argument3,
                                         unsigned long argument4);  // slot 55
};

// Slot 55: creates an Object_001E1220, gets its interface data_001E13A0 and sets it up (func_0014E2F0) with the
// first three arguments; *argument4 is the result or null. E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E0F00::func_0014E430(unsigned long argument1, unsigned long argument2,
                                              unsigned long argument3, unsigned long argument4)
{
    void **object = (void **)argument4;
    Object_001E1220 *created = new Object_001E1220;
    if (created) {
        long result = created->func_0014E200(&data_001E13A0, (void **)&created);
        if (result >= 0) {
            result = created->func_0014E2F0(argument1, (const unsigned long *)argument2, argument3);
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
