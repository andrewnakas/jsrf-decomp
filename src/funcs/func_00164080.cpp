struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

// The objects in the vector at +0x118 (the devices found).
struct Item {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();

    char unknown_04[0x38];
    Guid id;
    char unknown_4c[0x108];
    char name[0x120];
    unsigned char type;
};

// The std::vector of pointers at +0x118.
struct ItemVector {
    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
    Item *operator[](unsigned int index) const
    {
        return first[index];
    }

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

    long __stdcall func_00163EB0(const char *name, unsigned char index, Item **found);
    long __stdcall func_00163F30(const Guid *id, unsigned char index, Item **found);
    long __stdcall func_00163FD0(unsigned long type, unsigned char index, Item **found);

    void *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long block[0x41];
    unsigned long unknown_114;
    ItemVector items;
};

// Slot 5: gives out the device at the index in the low byte of the second argument, with a reference added. With a
// key, the index counts only the devices that match it: the second byte says how (1 a name, 2 an identifier, else a
// type). E_INVALIDARG without an out pointer or for an index past the end, 0x800401F0 (not initialised) while +0xc
// is null, 0x800710D8 when there is no device.
long __stdcall Object_001E19E0::func_00164080(void *argument1, void *argument2, void *argument3)
{
    if (unknown_0c) {
        if (argument3) {
            unsigned int count = items.size();
            unsigned int index = (unsigned char)(unsigned long)argument2;
            if (index < count) {
                if (argument1) {
                    if ((unsigned char)((unsigned long)argument2 >> 8) == 1)
                        return func_00163EB0((const char *)argument1, index, (Item **)argument3);
                    if ((unsigned char)((unsigned long)argument2 >> 8) == 2)
                        return func_00163F30((const Guid *)argument1, index, (Item **)argument3);
                    return func_00163FD0((unsigned long)argument1, index, (Item **)argument3);
                }
                Item *item = items[index];
                if (item) {
                    item->slot1();
                    *(Item **)argument3 = item;
                    return 0;
                }
                *(Item **)argument3 = 0;
                return 0x800710D8;
            }
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
