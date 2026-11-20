struct Guid;

// One of the objects in MGameSound8's list.
struct Voice {
    virtual void slot0();
    virtual unsigned long __stdcall slot1();
};

// The list at +0x1c (a std::vector of pointers: the executable carries its "vector<T> too long").
struct VoiceList {
    char allocator;
    Voice **first;
    Voice **last;
    Voice **end;

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
};

// MGameSound8's first interface: the table at 0x1E3A70.
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall func_00168AF0(unsigned int index, Voice **voice);
};

// MGameSound8's second interface, at +4: the table at 0x1E3A5C.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates (0x2c
// bytes).
struct MGameSound8 : FirstInterface, SecondInterface {
    virtual long __stdcall func_00168AF0(unsigned int index, Voice **voice);

    void *outer;
    long references;
    char unknown_10[0xc];
    VoiceList voices;
};

// Slot 5: entry `index` of the list at +0x1c, with a reference (its slot 1). 0x800401F0 (not initialised) while the
// list is empty, E_INVALIDARG for a null pointer, 0x800710D8 for an index past the end or an empty entry.
long __stdcall MGameSound8::func_00168AF0(unsigned int index, Voice **voice)
{
    if (voices.size() != 0) {
        if (voice) {
            if (index < voices.size() && voices.first[index]) {
                Voice *found = voices.first[index];
                found->slot1();
                *voice = found;
                return 0;
            }
            return 0x800710D8;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
