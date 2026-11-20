extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

extern long data_002651A0;

// The class factory of MRIFFFile (table 0x1E3CD8, right after the "MUSASHI.MRIFFFile.1" strings): slot 3 creates the
// object, slot 4 is this function.
struct MRIFFFileFactory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *outer, const Guid &id, void **object);
    virtual long __stdcall func_00172E70(int lock);
};

// Locks or unlocks the module: counts the lock in data_002651A0.
long __stdcall MRIFFFileFactory::func_00172E70(int lock)
{
    if (lock)
        _InterlockedIncrement(&data_002651A0);
    else
        _InterlockedDecrement(&data_002651A0);
    return 0;
}
