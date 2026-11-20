struct Guid;

extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

// Four words 0x19F024 fills in.
struct Caps {
    unsigned long words[4];
};

struct Sound;

// DirectSound's library code (0x19E000-0x1A1000).
long __stdcall func_0019E4C1(Sound *sound);
long __stdcall func_0019F024(Sound *sound, Caps *caps);

// The DirectSound object, called through inline wrappers of the library's functions.
struct Sound {
    // 0x19E4C1 returns 0 and does nothing else.
    long nothing()
    {
        return func_0019E4C1(this);
    }
    long caps(Caps *caps)
    {
        return func_0019F024(this, caps);
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
    virtual void slot6();
    virtual void slot7();
    virtual long __stdcall func_00168500(Caps *caps);
};

// MGameSound8's second interface, at +4: the table at 0x1E3A5C.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates (0x2c
// bytes).
struct MGameSound8 : FirstInterface, SecondInterface {
    virtual long __stdcall func_00168500(Caps *caps);

    void *outer;
    long references;
    char unknown_10[4];
    Sound *sound;
};

// Slot 8: clears the four words and has 0x19F024 fill them from the DirectSound object at +0x14 (after 0x19E4C1).
// E_INVALIDARG for a null pointer, 0x800401F0 (not initialised) without the object.
long __stdcall MGameSound8::func_00168500(Caps *caps)
{
    if (sound) {
        if (caps) {
            sound->nothing();
            memset(caps, 0, sizeof(Caps));
            return sound->caps(caps);
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
