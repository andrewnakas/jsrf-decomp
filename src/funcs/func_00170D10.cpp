struct Guid;

// The entries of the list at +0x3bc (0x254 bytes each).
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

// The class whose table is at 0x1E3C08 (30 slots, the same Release as 0x1E3B90).
struct Object_001E3C08 {
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
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual long __stdcall func_00170D10(unsigned int index);

    char unknown_04[0xc];
    void *ready;
    char unknown_14[0xf4];
    unsigned long first;
    unsigned long second;
    char unknown_110[0x2ac];
    ItemList items;
    unsigned int selected;
};

// Slot 25: keeps `index` - 1 at +0x3cc when the index is within the list at +0x3bc (entries of 0x254 bytes);
// E_INVALIDARG otherwise.
long __stdcall Object_001E3C08::func_00170D10(unsigned int index)
{
    if (index < items.size()) {
        selected = index - 1;
        return 0;
    }
    return 0x80070057;
}
