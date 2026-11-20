/* sym: ??0Object_001E410C@@QAE@PAUUnknown@@@Z = 0x00179990 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The number of live MUSASHI.MEvent objects.
extern long data_002651C8;

int __stdcall func_00145585(void *handle);

// The class whose table is at 0x1E410C: the class the MEvent factory (0x1E40C4) creates for IID_IUnknown and the
// interface 0x1E40EC.
struct Object_001E410C {
    Object_001E410C(Unknown *outer);
    virtual long __stdcall func_00179900(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00165570();
    virtual long __stdcall func_001797E0(int manual, int signalled);
    virtual long __stdcall func_00179A20(void **event);
    virtual long __stdcall func_00179840(unsigned long timeout);
    virtual long __stdcall func_001798C0();
    virtual long __stdcall func_001798E0();

    // Closes the event and lets go of the controlling object (inlined into the deleting destructor, 0x1799D0).
    virtual __forceinline ~Object_001E410C()
    {
        if (event)
            func_00145585(event);
        if (outer) {
            outer->slot2();
            outer = 0;
        }
        _InterlockedDecrement(&data_002651C8);
    }

    Unknown *outer;
    long references;
    void *event;
};

// Constructor: one reference, no event yet; holds a reference to the controlling object, if any, and counts the
// object.
Object_001E410C::Object_001E410C(Unknown *outer)
{
    this->outer = outer;
    references = 1;
    event = 0;
    if (outer)
        outer->slot1();
    _InterlockedIncrement(&data_002651C8);
}
