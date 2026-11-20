extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

extern long data_00265184;

// The class factory of DirectInput8 (table 0x1E20A0, right after the "MUSASHI.DirectInput8.1" strings): slot 3
// creates the
// object, slot 4 is this function.
struct DirectInput8Factory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *outer, const Guid &id, void **object);
    virtual long __stdcall func_00166630(int lock);
};

// Locks or unlocks the module: counts the lock in data_00265184.
long __stdcall DirectInput8Factory::func_00166630(int lock)
{
    if (lock)
        _InterlockedIncrement(&data_00265184);
    else
        _InterlockedDecrement(&data_00265184);
    return 0;
}
