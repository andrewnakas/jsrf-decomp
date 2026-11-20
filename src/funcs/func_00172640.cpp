extern "C" void *memset(void *destination, int value, unsigned int size);

struct Sound;

// DirectSound's library code: calls slot 1 (AddRef) of the DirectSound object.
unsigned long __stdcall func_0019E4C6(Sound *sound);

// The 0x23c-byte description slot 3 takes (its first word is its size).
struct Description {
    unsigned long size;
    unsigned long flags;
    Sound *sound;
    char unknown_0c[0x230];
};

#pragma pack(push, 4)
// The entries of the list at +0x3bc (0x254 bytes each): a copy of the description and the state kept with it.
struct Item {
    Description description;
    unsigned long unknown_23c;
    __int64 unknown_240;
    char unknown_248[0xc];
};
#pragma pack(pop)

// A std::vector of them.
struct ItemList {
    void func_0016F860(const Item &value);

    char allocator;
    Item *first;
    Item *last;
    Item *end;
};

// The class whose table is at 0x1E3C08 (30 slots, the same Release as 0x1E3B90).
struct Object_001E3C08 {
    virtual long __stdcall slot0(const struct Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00172640(void *argument);
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
    virtual long __stdcall func_00171030();

    char unknown_04[8];
    Sound *sound;
    char unknown_10[0x124];
    Description description;
    char unknown_370[0x4c];
    ItemList items;
};

// Slot 3: keeps a copy of the 0x23c-byte description in the list at +0x3bc and at +0x134, makes the buffer (slot 14)
// unless the description's flags have the top bit set, and keeps a reference to its DirectSound object at +0xc.
// E_INVALIDARG for a null description or one of another size.
long __stdcall Object_001E3C08::func_00172640(void *argument)
{
    Description *source = (Description *)argument;
    if (source && source->size == 0x23c) {
        Item item;
        memset(&item, 0, sizeof(item));
        item.description = *source;
        items.func_0016F860(item);
        description = *source;
        long result;
        if (description.flags & 0x80000000) {
            result = 0;
        } else {
            result = func_00171030();
            if (result < 0)
                return result;
        }
        func_0019E4C6(description.sound);
        sound = description.sound;
        return result;
    }
    return 0x80070057;
}
