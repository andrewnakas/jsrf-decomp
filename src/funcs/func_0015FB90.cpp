extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

extern long data_00265178;

// The class factory of MGameInput8 (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings): slot 3 creates the
// object, slot 4 is this function.
struct MGameInput8Factory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *outer, const Guid &id, void **object);
    virtual long __stdcall func_0015FB90(int lock);
};

// Locks or unlocks the module: counts the lock in data_00265178.
long __stdcall MGameInput8Factory::func_0015FB90(int lock)
{
    if (lock)
        _InterlockedIncrement(&data_00265178);
    else
        _InterlockedDecrement(&data_00265178);
    return 0;
}
