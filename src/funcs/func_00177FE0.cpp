extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);

struct Guid;

// MGameInput8, the class its factory (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings) creates; its
// table is at 0x1E1900. Most MUSASHI tables hold this same function in slot 1 (folded).
struct MGameInput8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();

    char unknown_04[4];
    long references;
};

// AddRef (slot 1): counts a reference and returns the new count.
unsigned long __stdcall MGameInput8::func_00177FE0()
{
    return _InterlockedIncrement(&references);
}
