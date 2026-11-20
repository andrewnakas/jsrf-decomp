struct Guid;

// One of the objects in MGameSound8's list.
struct Voice {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
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
    virtual long __stdcall slot13(void *, void *);
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

// MGameSound8's first interface: the table at 0x1E3A70 up to slot 34.
struct FirstInterface {
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
    virtual long __stdcall func_00168610(unsigned int index, void *argument1, void *argument2);
};

// MGameSound8's second interface, at +4: the table at 0x1E3A5C.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates (0x2c
// bytes).
struct MGameSound8 : FirstInterface, SecondInterface {
    virtual long __stdcall func_00168610(unsigned int index, void *argument1, void *argument2);

    void *outer;
    long references;
    char unknown_10[0xc];
    VoiceList voices;
};

// Slot 12: passes its arguments on to slot 13 of entry `index` of the list at +0x1c. 0x800401F0 (not initialised)
// while the list is empty, 0x800710D8 for an index past its end or an empty entry.
long __stdcall MGameSound8::func_00168610(unsigned int index, void *argument1, void *argument2)
{
    if (voices.size() != 0) {
        if (index < voices.size() && voices.first[index])
            return voices.first[index]->slot13(argument1, argument2);
        return 0x800710D8;
    }
    return 0x800401F0;
}
