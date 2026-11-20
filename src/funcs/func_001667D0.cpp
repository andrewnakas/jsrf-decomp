extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

// DirectInput8, the class its factory (table 0x1E20A0, after the "MUSASHI.DirectInput8.1" strings) creates; its table
// is at 0x1E21A0.
struct DirectInput8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall func_001667D0();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual ~DirectInput8();

    char unknown_04[4];
    long references;
};

// Release (slot 2): drops a reference; the last one deletes the object through its destructor (slot 11).
unsigned long __stdcall DirectInput8::func_001667D0()
{
    if (_InterlockedDecrement(&references) == 0) {
        delete this;
        return 0;
    }
    return references;
}
