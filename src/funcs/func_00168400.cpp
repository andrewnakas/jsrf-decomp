extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

// The interface the second interface's slot 3 gives out (in the MGameSound8 factory's data, after its table).
extern const Guid data_001E38FC;

// Equal when they are the same object or have the same sixteen bytes (the out-of-line copy is at 0x15FA30).
inline bool operator==(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}

struct Sound;

// DirectSound's library code: 0x19E4C6 calls slot 1 (AddRef) of the object.
unsigned long __stdcall func_0019E4C6(Sound *sound);

// The DirectSound object, called through inline wrappers of the library's functions.
struct Sound {
    unsigned long add_reference()
    {
        return func_0019E4C6(this);
    }
};

// MGameSound8's first interface: the table at 0x1E3A70.
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MGameSound8's second interface, at +4: the table at 0x1E3A5C (the first three slots are adjustor thunks to
// MGameSound8's own).
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00168400(const Guid &id, void **object);
};

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates (0x2c
// bytes).
struct MGameSound8 : FirstInterface, SecondInterface {
    virtual long __stdcall func_00168400(const Guid &id, void **object);

    void *outer;
    long references;
    char unknown_10[4];
    Sound *sound;
};

// The second interface's slot 3: gives out the DirectSound object at +0x14, with a reference, for the interface
// 0x1E38FC. 0x800401F0 (not initialised) without it, E_INVALIDARG for a null pointer, E_NOINTERFACE for any other
// interface.
long __stdcall MGameSound8::func_00168400(const Guid &id, void **object)
{
    if (sound) {
        if (object) {
            if (id == data_001E38FC) {
                sound->add_reference();
                *object = sound;
                return 0;
            }
            *object = 0;
            return 0x80004002;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
