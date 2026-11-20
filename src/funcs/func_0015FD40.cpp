extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

// MGameInput8, the class its factory (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings) creates; its table
// is at 0x1E1900. The table at 0x1E4020 holds the same function (folded).
struct MGameInput8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall func_0015FD40();
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
    virtual ~MGameInput8();

    char unknown_04[4];
    long references;
};

// Release (slot 2): drops a reference; the last one deletes the object through its destructor (slot 18).
unsigned long __stdcall MGameInput8::func_0015FD40()
{
    if (_InterlockedDecrement(&references) == 0) {
        delete this;
        return 0;
    }
    return references;
}
