/* sym: ??0Object_001E3FB0@@QAE@PAUUnknown@@@Z = 0x00177280 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);
void __cdecl operator delete(void *memory) throw();

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// A block of 0x10 bytes: its size, flags, and the two words the flags ask for.
struct Info;

// The number of live MFile2 objects.
extern long data_002651BC;

// The class whose table is at 0x1E3FB0: the one the MFile2 factory (0x1E3F1C) creates for the interface 0x1E3F34
// (0x18 bytes). Slots 7 and 8 hold the same functions as the table at 0x1E3FE4 and its Release is the one of
// 0x1E202C (the linker folded the identical functions).
struct Object_001E3FB0 {
    Object_001E3FB0(Unknown *outer);
    virtual long __stdcall func_00177190(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00165E90();
    virtual long __stdcall func_00176D30(void *argument);
    virtual long __stdcall func_00176F70(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_00176E30(void *argument1, void *argument2);
    virtual long __stdcall func_00176EC0(void *argument);
    virtual long __stdcall func_001773E0(void *argument);
    virtual long __stdcall func_00177400(void *argument1, void *argument2);
    virtual long __stdcall func_00177120(unsigned long *value);
    virtual long __stdcall func_00177080(const Info *info);
    virtual long __stdcall func_001770D0(Info *info);

    // Lets go of the inner object and the controlling object and counts the object out (inlined into the deleting
    // destructor 0x177220).
    virtual __forceinline ~Object_001E3FB0()
    {
        if (inner) {
            inner->slot2();
            inner = 0;
        }
        if (outer) {
            outer->slot2();
            outer = 0;
        }
        _InterlockedDecrement(&data_002651BC);
    }

    Unknown *outer;
    long references;
    Unknown *inner;
    unsigned long first;
    unsigned long second;
};

// Constructor: one reference, no inner object, the two words zero; holds a reference to the controlling object, if
// any, and counts the object in.
Object_001E3FB0::Object_001E3FB0(Unknown *outer) : outer(outer), references(1), inner(0), first(0), second(0)
{
    if (this->outer)
        this->outer->slot1();
    _InterlockedIncrement(&data_002651BC);
}
