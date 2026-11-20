extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

// The class whose table is at 0x1E3FE4. The table at 0x1E420C holds the same function (folded).
struct Object_001E3FE4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall func_0017B6A0();
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
    virtual ~Object_001E3FE4();

    char unknown_04[4];
    long references;
};

// Release (slot 2): drops a reference; the last one deletes the object through its destructor (slot 14).
unsigned long __stdcall Object_001E3FE4::func_0017B6A0()
{
    if (_InterlockedDecrement(&references) == 0) {
        delete this;
        return 0;
    }
    return references;
}
