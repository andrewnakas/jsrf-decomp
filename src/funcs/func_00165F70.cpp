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
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall func_00165F70(Values *values);

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

// Slot 5: copies the values the flags pick out of the description. E_INVALIDARG for a null pointer or a block whose
// first word is not 0x18, 0x800401F0 (not initialised) before slot 3.
long __stdcall Object_001E202C::func_00165F70(Values *values)
{
    if (description.size == sizeof(Description)) {
        if (values && values->size == sizeof(Values)) {
            if (values->flags & 2) {
                values->values[2] = description.values[2];
                values->values[3] = description.values[3];
            }
            if (values->flags & 1) {
                values->values[0] = description.values[0];
                values->values[1] = description.values[1];
            }
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
