extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

extern long data_002651C4;

// The class factory of MEvent (table 0x1E40C4, right after the "MUSASHI.MEvent.1" strings): slot 3 creates the
// object, slot 4 is this function.
struct MEventFactory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *outer, const Guid &id, void **object);
    virtual long __stdcall func_001795E0(int lock);
};

// Locks or unlocks the module: counts the lock in data_002651C4.
long __stdcall MEventFactory::func_001795E0(int lock)
{
    if (lock)
        _InterlockedIncrement(&data_002651C4);
    else
        _InterlockedDecrement(&data_002651C4);
    return 0;
}
