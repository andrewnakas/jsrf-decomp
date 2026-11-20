struct Guid;

// One of the objects in MGameSound8's list.
struct Voice {
    virtual void slot0();
    virtual void slot1();
    virtual unsigned long __stdcall slot2();
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
    virtual void slot5();
    virtual long __stdcall func_00168EC0(unsigned int index);
};

// MGameSound8's second interface, at +4: the table at 0x1E3A5C.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates (0x2c
// bytes).
struct MGameSound8 : FirstInterface, SecondInterface {
    virtual long __stdcall func_00168EC0(unsigned int index);

    void *outer;
    long references;
    char unknown_10[0xc];
    VoiceList voices;
};

// Slot 6: lets go of entry `index` of the list at +0x1c (its slot 2) and empties the entry; index -1 lets go of
// every entry and frees the list.
long __stdcall MGameSound8::func_00168EC0(unsigned int index)
{
    if (index == 0xFFFFFFFF) {
        for (Voice **voice = voices.first; voice != voices.last; ++voice) {
            if (*voice) {
                (*voice)->slot2();
                *voice = 0;
            }
        }
        if (voices.first)
            operator delete(voices.first);
        voices.first = 0;
        voices.last = 0;
        voices.end = 0;
        return 0;
    }
    if (index < voices.size() && voices.first[index]) {
        voices.first[index]->slot2();
        voices.first[index] = 0;
    }
    return 0;
}
