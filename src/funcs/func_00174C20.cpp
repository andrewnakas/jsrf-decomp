extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MGameSound8's first interface: the table at 0x1E3A70 up to slot 34.
struct FirstInterface {
    virtual long __stdcall func_00168310(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00168230();
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
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
};

// MGameSound8's second interface, at +4: the table at 0x1E3A5C (the first three slots are adjustor thunks to
// MGameSound8's own).
struct SecondInterface {
    virtual long __stdcall func_00168310(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00168230();
    virtual long __stdcall slot3(const Guid &id, void **object);
};

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates. Its own
// table is 0x1E3A70 (36 slots; the destructor is the last).
struct MGameSound8 : FirstInterface, SecondInterface {
    virtual long __stdcall func_00168310(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00168230();
    virtual ~MGameSound8();

    Unknown *outer;
    long references;
};

// AddRef (slot 1; the second interface reaches it through the adjustor thunk 0x168FF0): counts a reference at +0xc
// and returns the new count. MemStream's table (0x1E3EA8) holds the same function.
unsigned long __stdcall MGameSound8::func_00174C20()
{
    return _InterlockedIncrement(&references);
}
