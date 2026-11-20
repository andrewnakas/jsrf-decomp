extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

// The factory of MGameInput8 (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings). The factories of the
// other MUSASHI classes hold the same function in slot 2 (folded).
struct MGameInput8Factory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall func_001664D0();
    virtual long __stdcall slot3(void *outer, const Guid &id, void **object);
    virtual long __stdcall slot4(int lock);
    virtual ~MGameInput8Factory();

    char unknown_04[4];
    long references;
};

// Release (slot 2): drops a reference; the last one deletes the object through its destructor (slot 5).
unsigned long __stdcall MGameInput8Factory::func_001664D0()
{
    if (_InterlockedDecrement(&references) == 0) {
        delete this;
        return 0;
    }
    return references;
}
