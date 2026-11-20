struct Guid;

struct Sound;

// DirectSound's library code (0x19E000-0x1A1000).
long __stdcall func_001A0D9C(void *device, Sound **sound, void *outer);
void __stdcall func_0019E523();
long __stdcall func_0019E4BC(Sound *sound, void *window, unsigned long level);
long __stdcall func_0019E4C1(Sound *sound);

// The DirectSound object, called through inline wrappers of the library's functions.
struct Sound {
    // 0x19E4BC and 0x19E4C1 return 0 and do nothing else.
    long level(void *window, unsigned long level)
    {
        return func_0019E4BC(this, window, level);
    }
    long nothing()
    {
        return func_0019E4C1(this);
    }
};
unsigned long __stdcall func_00147378();

// MGameSound8's first interface: the table at 0x1E3A70.
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00168480(void *window);
};

// MGameSound8's second interface, at +4: the table at 0x1E3A5C.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates (0x2c
// bytes).
struct MGameSound8 : FirstInterface, SecondInterface {
    virtual long __stdcall func_00168480(void *window);

    void *outer;
    long references;
    void *window;
    Sound *sound;
    unsigned long flags;
};

// Slot 3: creates the DirectSound object into +0x14 (0x1A0D9C) after noting the value 0x147378 gives in +0x18 and
// the argument in +0x10, then passes the argument and 3 to 0x19E4BC. A second call fails with 0x800401F1 (already
// initialised).
long __stdcall MGameSound8::func_00168480(void *window)
{
    long result;
    if (sound) {
        result = 0x800401F1;
    } else {
        flags = func_00147378();
        this->window = window;
        result = func_001A0D9C(0, &sound, 0);
        if (result >= 0) {
            func_0019E523();
            result = sound->level(this->window, 3);
            if (result >= 0)
                sound->nothing();
        }
    }
    return result;
}
