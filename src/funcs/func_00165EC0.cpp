struct Guid;

// The description slot 3 takes (0x5c bytes, its size first); the object is set up while its copy at +0x30 has the
// right size.
struct Description {
    unsigned long size;
    unsigned long unknown_04;
    unsigned long values[4];
    void *entries[8];
    char block[0x20];
    unsigned long last;
};

// What slots 4 and 5 take (0x18 bytes, its size first): flag 1 covers the first two values, flag 2 the other two.
struct Values {
    unsigned long size;
    unsigned long flags;
    unsigned long values[4];
};

// What slot 6 fills in.
struct Info {
    unsigned long first;
    unsigned long second;
    unsigned long third;
    unsigned long fourth;
    char *block;
    unsigned long last;
};

// The class whose table is at 0x1E202C.
struct Object_001E202C {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00165EC0(const Description *description);

    char unknown_04[8];
    unsigned long first;
    unsigned long second;
    unsigned long fourth;
    char unknown_18[4];
    unsigned long third;
    char unknown_20[0xc];
    unsigned int count;
    Description description;
};

// Slot 3: keeps a copy of the description at +0x30 and counts its leading non-null entries (at most 8) into +0x2c.
// 0x800401F1 when already set up, E_INVALIDARG for a null pointer or a description whose first word is not 0x5c.
long __stdcall Object_001E202C::func_00165EC0(const Description *description)
{
    if (this->description.size == sizeof(Description))
        return 0x800401F1;
    if (description && description->size == sizeof(Description)) {
        unsigned int count;
        for (count = 0; count < 8; ++count) {
            if (!description->entries[count])
                break;
        }
        this->count = count;
        this->description = *description;
        return 0;
    }
    return 0x80070057;
}
