struct Guid;

// The class whose table is at 0x1E410C: the class the MEvent factory (0x1E40C4) creates for IID_IUnknown and the
// interface 0x1E40EC. The table at 0x1E4130 holds the same function in slot 4.
struct Object_001E410C {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall func_00179A20(void **event);

    char unknown_04[8];
    void *event;
};

// Slot 4: copies the event at +0xc out. Fails with 0x800401F0 (not initialised) when there is none, and with
// E_INVALIDARG for a null pointer.
long __stdcall Object_001E410C::func_00179A20(void **event)
{
    if (this->event) {
        if (event) {
            *event = this->event;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
