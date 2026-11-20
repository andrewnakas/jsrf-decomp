extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

// The class whose table is at 0x1E1FE4. The tables at 0x1E2008, 0x1E3C80 and 0x1E410C hold the same function
// (folded).
struct Object_001E1FE4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall func_00165570();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual ~Object_001E1FE4();

    char unknown_04[4];
    long references;
};

// Release (slot 2): drops a reference; the last one deletes the object through its destructor (slot 8).
unsigned long __stdcall Object_001E1FE4::func_00165570()
{
    if (_InterlockedDecrement(&references) == 0) {
        delete this;
        return 0;
    }
    return references;
}
