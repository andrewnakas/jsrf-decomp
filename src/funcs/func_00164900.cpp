void __cdecl operator delete(void *memory) throw();

struct Guid;

// The objects in the vector at +0x118 (the devices found).
struct Item {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The std::vector of pointers at +0x118.
struct ItemVector {
    char allocator;
    Item **first;
    Item **last;
    Item **end;
};

// The class whose table is at 0x1E19E0 (0x144 bytes).
struct Object_001E19E0 {
    virtual long __stdcall func_00163DB0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00163B90();
    virtual long __stdcall func_00165130(void *argument1, void *argument2);
    virtual long __stdcall func_001652E0(void *argument);
    virtual long __stdcall func_00164080(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00164900(void *argument);

    void *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long block[0x41];
    unsigned long unknown_114;
    ItemVector items;
};

// Slot 6: lets go of the device (its slot 2) and empties its entry of the vector at +0x118; 0x800710D8 when it is
// not there. A null device lets go of every entry and frees the vector.
long __stdcall Object_001E19E0::func_00164900(void *argument)
{
    Item *item = (Item *)argument;
    if (item) {
        long result = 0x800710D8;
        for (Item **entry = items.first, **last = items.last; entry != last; ++entry) {
            if (*entry == item) {
                if (*entry) {
                    (*entry)->slot2();
                    *entry = 0;
                }
                result = 0;
                break;
            }
        }
        return result;
    }
    for (Item **entry = items.first; entry != items.last; ++entry) {
        if (*entry) {
            (*entry)->slot2();
            *entry = 0;
        }
    }
    if (items.first)
        operator delete(items.first);
    items.first = 0;
    items.last = 0;
    items.end = 0;
    return 0;
}
