struct Guid;

int __stdcall func_00145B46(void *event);

// The class whose table is at 0x1E410C: the class the MEvent factory (0x1E40C4) creates for IID_IUnknown and the
// interface 0x1E40EC.
struct Object_001E410C {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall func_001798E0();

    char unknown_04[8];
    void *event;
};

// Slot 7: resets the event at +0xc (func_00145B46), or fails with 0x800401F0 (not initialised) when there is none.
long __stdcall Object_001E410C::func_001798E0()
{
    if (event) {
        func_00145B46(event);
        return 0;
    }
    return 0x800401F0;
}
