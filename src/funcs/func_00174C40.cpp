extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MemStream's first interface: the table at 0x1E3EA8 up to slot 16.
struct FirstInterface {
    virtual long __stdcall func_001753D0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00174C40();
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
};

// MemStream's second interface, at +4: the table at 0x1E3E98 (the first three slots are adjustor thunks to
// MemStream's own).
struct SecondInterface {
    virtual long __stdcall func_001753D0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00174C40();
    virtual long __stdcall slot3(void *first, void *second);
};

// MemStream, the class its factory (table 0x1E3E80, after the "MUSASHI.MemStream.1" strings) creates. Its own table
// is 0x1E3EA8 (18 slots; the destructor is the last).
struct MemStream : FirstInterface, SecondInterface {
    virtual long __stdcall func_001753D0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00174C40();
    virtual ~MemStream();

    Unknown *outer;
    long references;
};

// Release (slot 2; the second interface reaches it through an adjustor thunk): drops a reference; the last one
// deletes the object through its destructor (slot 17).
unsigned long __stdcall MemStream::func_00174C40()
{
    if (_InterlockedDecrement(&references) == 0) {
        delete this;
        return 0;
    }
    return references;
}
