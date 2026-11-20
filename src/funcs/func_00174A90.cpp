extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

extern long data_002651AC;

// The class factory of MemStream (table 0x1E3E80, right after the "MUSASHI.MemStream.1" strings): slot 3 creates the
// object, slot 4 is this function.
struct MemStreamFactory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *outer, const Guid &id, void **object);
    virtual long __stdcall func_00174A90(int lock);
};

// Locks or unlocks the module: counts the lock in data_002651AC.
long __stdcall MemStreamFactory::func_00174A90(int lock)
{
    if (lock)
        _InterlockedIncrement(&data_002651AC);
    else
        _InterlockedDecrement(&data_002651AC);
    return 0;
}
