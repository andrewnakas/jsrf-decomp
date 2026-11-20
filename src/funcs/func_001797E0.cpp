struct Guid;

// The system library's event and error functions.
void *__stdcall func_00145AC5(void *attributes, int manual, int signalled, const char *name);
unsigned long __stdcall func_00146401();

// The class whose table is at 0x1E410C: the class the MEvent factory (0x1E40C4) creates for IID_IUnknown and the
// interface 0x1E40EC.
struct Object_001E410C {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_001797E0(int manual, int signalled);

    char unknown_04[8];
    void *event;
};

// Slot 3: creates the event (0x145AC5) into +0xc. 0x800401F1 when there is one already; when the creation fails, the
// last system error as an HRESULT (0x146401, read once for the test and once for the value).
long __stdcall Object_001E410C::func_001797E0(int manual, int signalled)
{
    if (event)
        return 0x800401F1;
    event = func_00145AC5(0, manual, signalled, 0);
    if (event)
        return 0;
    return (long)func_00146401() <= 0 ? (long)func_00146401() : (long)((func_00146401() & 0xFFFF) | 0x80070000);
}
