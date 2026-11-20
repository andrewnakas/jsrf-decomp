struct Guid;
struct Holder;
struct Surface;
struct Sound;
struct Item;
struct Entry;
struct Slot;
extern const Guid data_001E1748;

// A class whose table is at 0x1E1640 (26 slots, 0x18 bytes; Release 0x159D40).
struct Object_001E1640 {
    virtual long __stdcall func_00159B70(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014E1F0_2();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_00159D40();  // slot 2
    virtual long __stdcall func_0015E8D0(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 3
    virtual long __stdcall func_0015D9E0(unsigned long argument1, unsigned long argument2, unsigned long argument3,
                                         unsigned long argument4);  // slot 4
    virtual void __stdcall func_001583F0(Holder *holder);  // slot 5, folded with 0x1E1498's slot 4
    virtual long __stdcall func_00159510(Surface **holder, void **data, unsigned long *third,
                                         unsigned long *first);  // slot 6
    virtual long __stdcall func_00159570(Holder *holder);  // slot 7
    virtual long __stdcall func_00159580(Holder *holder, unsigned long *first, unsigned long *second);  // slot 8
    virtual long __stdcall func_001595D0(Holder *holder);  // slot 9
    virtual long __stdcall func_00159C90(Sound *sound, void **data, unsigned int *frame,
                                         unsigned long *value);  // slot 10
    virtual long __stdcall func_00159D00(Sound *sound);  // slot 11
    virtual long __stdcall func_00159700(unsigned long argument1, unsigned long argument2);  // slot 12
    virtual long __stdcall func_00159860(int index);  // slot 13
    virtual long __stdcall func_00159890(unsigned long argument1, unsigned long argument2);  // slot 14
    virtual int __stdcall func_001595E0(Item *item, int *extra);  // slot 15
    virtual void __stdcall func_00159600(Holder *holder);  // slot 16
    virtual long __stdcall func_0015D1C0(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 17
    virtual long __stdcall func_0015D2E0(unsigned long argument1);  // slot 18
    virtual long __stdcall func_001596E0(unsigned long value);  // slot 19
    virtual long __stdcall func_0015CE20(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 20
    virtual long __stdcall func_0015D000(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 21
    virtual long __stdcall func_00159650(Entry *entry, unsigned long first, unsigned long second);  // slot 22
    virtual long __stdcall func_001596B0(Holder *holder);  // slot 23
    virtual long __stdcall func_0015C730(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 24
    virtual long __stdcall func_00165400_1(int first, int second);  // slot 25: folded with MUSASHI 0x1E1FE4's slot 6

    Object_001E1640() : slots(0), count(0), value_0C(0), value_10(0), references(0) {}
    ~Object_001E1640() {}

    long __stdcall func_00159BB0(unsigned int count, unsigned long flags);

    Slot *slots;
    unsigned int count;
    int value_0C;
    int value_10;
    unsigned long references;
};

// The factory object whose table is at 0x1E13F0.
struct Object_001E13F0 {
    virtual long __stdcall func_00159D70(unsigned long first, unsigned long second, void **object);  // slot 4
};

// Creates an Object_001E1640, gets its interface data_001E1748 and sets it up (func_00159BB0) with both arguments;
// *object is the result or null. E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E13F0::func_00159D70(unsigned long first, unsigned long second, void **object)
{
    Object_001E1640 *created = new Object_001E1640;
    if (created) {
        long result = created->func_00159B70(&data_001E1748, (void **)&created);
        if (result >= 0) {
            result = created->func_00159BB0(first, second);
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
