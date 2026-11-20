struct Guid;

// The stream at +0xc (slot 6 gives out its position).
struct Inner {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(unsigned __int64 *position);
};

// The class whose table is at 0x1E3FB0: a window from +0x10 to +0x14 of the stream at +0xc.
struct Object_001E3FB0 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual long __stdcall func_00176EC0(void *argument);

    void *outer;
    long references;
    Inner *inner;
    unsigned long start;
    unsigned long end;
};

// Slot 17: gives out the stream's position (its slot 6) as a 64-bit value inside the window: the start before it,
// the end past it, else the distance from the start. E_INVALIDARG for a null pointer, 0x800401F0 (not initialised)
// without a stream.
long __stdcall Object_001E3FB0::func_00176EC0(void *argument)
{
    long result;
    if (inner) {
        unsigned __int64 *out = (unsigned __int64 *)argument;
        if (out) {
            unsigned __int64 position;
            result = inner->slot6(&position);
            if (result >= 0) {
                if (position < start)
                    *out = start;
                else if (position >= end)
                    *out = end;
                else
                    *out = position - start;
            }
        } else {
            result = 0x80070057;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
