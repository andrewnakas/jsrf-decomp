struct Guid;

// One of the objects in MGameSound8's list.
struct Voice {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual long __stdcall slot4();
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

// DirectSound's library code (0x19E000-0x1A1000).
long __stdcall func_0019FE28(void *sound);
void __stdcall func_0019F260();

// MGameSound8's first interface: the table at 0x1E3A70.
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall func_00168550();
};

// MGameSound8's second interface, at +4: the table at 0x1E3A5C.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates (0x2c
// bytes).
struct MGameSound8 : FirstInterface, SecondInterface {
    virtual long __stdcall func_00168550();

    void *outer;
    long references;
    char unknown_10[4];
    void *sound;
    char unknown_18[4];
    VoiceList voices;
};

// Slot 7: calls slot 4 of every entry of the list at +0x1c and keeps the last result, then hands the DirectSound
// object at +0x14 to 0x19FE28 and calls 0x19F260. 0x800401F0 (not initialised) while the list is empty.
long __stdcall MGameSound8::func_00168550()
{
    if (voices.size() != 0) {
        long result = 0;
        for (Voice **voice = voices.first; voice != voices.last; ++voice) {
            if (*voice)
                result = (*voice)->slot4();
        }
        func_0019FE28(sound);
        func_0019F260();
        return result;
    }
    return 0x800401F0;
}
