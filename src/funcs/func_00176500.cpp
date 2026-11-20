extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

extern long data_002651B8;

// The class factory of MFile2 (table 0x1E3F1C, right after the "MUSASHI.MFile2.1" strings): slot 3 creates the
// object, slot 4 is this function.
struct MFile2Factory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *outer, const Guid &id, void **object);
    virtual long __stdcall func_00176500(int lock);
};

// Locks or unlocks the module: counts the lock in data_002651B8.
long __stdcall MFile2Factory::func_00176500(int lock)
{
    if (lock)
        _InterlockedIncrement(&data_002651B8);
    else
        _InterlockedDecrement(&data_002651B8);
    return 0;
}
