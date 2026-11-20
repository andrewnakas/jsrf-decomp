struct Guid;

// The entries of the list at +0x4e4 (0x254 bytes each).
struct Item {
    char unknown[0x254];
};

// A std::vector of them.
struct ItemList {
    char allocator;
    Item *first;
    Item *last;
    Item *end;

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
};

struct Thing;

// The class whose table is at 0x1E3B90 (30 slots; the destructor is the last).
struct Object_001E3B90 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual long __stdcall func_0016C580(unsigned long first, unsigned long second);
    long __stdcall func_0016B840(Thing **thing);
    long __stdcall func_0016C4F0(Thing *thing);

    char unknown_04[0xc];
    void *ready;
    char unknown_14[0x248];
    unsigned long first;
    unsigned long second;
    char unknown_264[0x280];
    ItemList items;
    unsigned int selected;
};

// Slot 13: takes an object from 0x16B840, keeps the two words at +0x25c and +0x260 and passes the object on to
// 0x16C4F0. 0x800401F0 (not initialised) while +0x10 is null.
long __stdcall Object_001E3B90::func_0016C580(unsigned long first, unsigned long second)
{
    long result;
    if (ready) {
        Thing *thing;
        result = func_0016B840(&thing);
        if (result >= 0) {
            this->first = first;
            this->second = second;
            result = func_0016C4F0(thing);
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
