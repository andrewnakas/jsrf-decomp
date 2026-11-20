extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

extern long data_002651D0;

// The class factory of MThread (table 0x1E4190, right after the "MUSASHI.MThread.1" strings): slot 3 creates the
// object, slot 4 is this function.
struct MThreadFactory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *outer, const Guid &id, void **object);
    virtual long __stdcall func_0017A810(int lock);
};

// Locks or unlocks the module: counts the lock in data_002651D0.
long __stdcall MThreadFactory::func_0017A810(int lock)
{
    if (lock)
        _InterlockedIncrement(&data_002651D0);
    else
        _InterlockedDecrement(&data_002651D0);
    return 0;
}
