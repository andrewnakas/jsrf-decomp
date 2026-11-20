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

struct EntryList {
    char unknown[0x10];
};

// What slot 9 fills in (0x28c bytes, its size first).
struct Description {
    unsigned long size;
    State state;
    Caps caps;
    Format format;
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
    virtual long __stdcall func_00161D30(Description *description);

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

// Slot 9: copies the three blocks out into a 0x28c-byte description, each only when its own size word matches.
// E_INVALIDARG for a null pointer or a description whose first word is not 0x28c, 0x800401F0 (not initialised) without
// the object at +0x3b0.
long __stdcall Object_001E1968::func_00161D30(Description *description)
{
    if (inner) {
        if (description && description->size == sizeof(Description)) {
            if (description->caps.size == sizeof(Caps))
                description->caps = caps;
            if (description->state.size == sizeof(State))
                description->state = state;
            if (description->format.size == sizeof(Format))
                description->format = format;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
