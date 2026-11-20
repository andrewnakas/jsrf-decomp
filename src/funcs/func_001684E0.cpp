struct Guid;

// DirectSound's library code (0x19E000-0x1A1000).
long __stdcall func_0019F040(void *sound, void *argument);

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
    virtual void slot8();
    virtual long __stdcall func_001684E0(void *argument);
};

// MGameSound8's second interface, at +4: the table at 0x1E3A5C.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates (0x2c
// bytes).
struct MGameSound8 : FirstInterface, SecondInterface {
    virtual long __stdcall func_001684E0(void *argument);

    void *outer;
    long references;
    char unknown_10[4];
    void *sound;
};

// Slot 9: passes the argument on to 0x19F040 with the DirectSound object at +0x14; 0x800401F0 (not initialised)
// without one.
long __stdcall MGameSound8::func_001684E0(void *argument)
{
    if (sound)
        return func_0019F040(sound, argument);
    return 0x800401F0;
}
