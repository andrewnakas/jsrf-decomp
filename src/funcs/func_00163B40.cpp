struct Guid;

// The blocks the object keeps (each with its size first): 0x244 bytes at +0x28, 0x2c bytes at +0x26c (its byte at
// +8 is the kind) and 0x18 bytes at +0x298.
struct State {
    unsigned long size;
    unsigned long words[0x90];
};

struct Caps {
    unsigned long size;
    unsigned long unknown_04;
    unsigned char kind;
    char unknown_09[3];
    unsigned long words[8];
};

struct Format {
    unsigned long size;
    unsigned long words[5];
};

// The object at +0x3b0.
struct Inner {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The objects in the lists at +0x3c8 and +0x3d8.
struct Entry {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
};

// A std::vector of pointers.
struct EntryList {
    char allocator;
    Entry **first;
    Entry **last;
    Entry **end;

    void func_001637B0(Entry *const &value);
};

// The class whose table is at 0x1E1968.
struct Object_001E1968 {
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
    virtual long __stdcall func_00163B40(Entry *entry);

    char unknown_04[0xc];
    void *value;
    char unknown_14[0x14];
    State state;
    Caps caps;
    Format format;
    char unknown_2b0[0x100];
    Inner *inner;
    char unknown_3b4[0x10];
    void *other;
    EntryList first;
    EntryList second;
};

// Slot 17: appends the object, with a reference, to the list at +0x3d8 (0x1637B0). E_INVALIDARG for a null object,
// 0x800401F0 (not initialised) without the object at +0x3b0.
long __stdcall Object_001E1968::func_00163B40(Entry *entry)
{
    if (inner) {
        if (entry) {
            entry->slot1();
            second.func_001637B0(entry);
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
