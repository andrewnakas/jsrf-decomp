/* sym: ??0DirectInput8@@QAE@PAUUnknown@@@Z = 0x00166C30 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);
extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

struct Key;

// The objects in the table at +0x18.
struct Entry {
    virtual void slot0();
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The number of live DirectInput8 objects.
extern long data_00265188;

// DirectInput8, the class its factory (table 0x1E20A0, after the "MUSASHI.DirectInput8.1" strings) creates; its table
// is at 0x1E21A0 (0x28 bytes).
struct DirectInput8 {
    DirectInput8(Unknown *outer);
    virtual long __stdcall func_00166BA0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_001667D0();
    virtual long __stdcall func_00166940(const Key *key, Entry **entry, void *);
    virtual long __stdcall func_001669A0(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_001504B0(void *argument);
    virtual long __stdcall func_00167CB0(void *argument1, unsigned long argument2);
    virtual long __stdcall func_00166800(void *argument1, void *argument2);
    virtual long __stdcall func_001526D0(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00166B40(void *argument1, void *argument2, void *argument3, void *argument4,
                                         unsigned long argument5);
    virtual long __stdcall func_00167CC0(void *argument1, void *argument2, unsigned long argument3, void *argument4);

    // Lets go of the four entries and of the controlling object and counts the object out (0x166B50, called by the
    // deleting destructor 0x166C80).
    virtual ~DirectInput8()
    {
        for (int i = 0; i < 4; i++) {
            if (entries[i]) {
                entries[i]->slot2();
                entries[i] = 0;
            }
        }
        if (outer) {
            outer->slot2();
            outer = 0;
        }
        _InterlockedDecrement(&data_00265188);
    }

    Unknown *outer;
    long references;
    void *ready;
    unsigned long unknown_10;
    unsigned long unknown_14;
    Entry *entries[4];
};

// Constructor: one reference, not ready, no entries; holds a reference to the controlling object, if any, and
// counts the object in.
DirectInput8::DirectInput8(Unknown *outer)
{
    this->outer = outer;
    references = 1;
    ready = 0;
    unknown_10 = 0;
    unknown_14 = 0;
    if (outer)
        outer->slot1();
    memset(entries, 0, sizeof(entries));
    _InterlockedIncrement(&data_00265188);
}
