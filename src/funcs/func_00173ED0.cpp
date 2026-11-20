struct Guid;

// The object at +0x10.
struct Source {
    virtual void slot0();
    virtual unsigned long __stdcall slot1();
};

// The class whose table is at 0x1E3DE4.
struct Object_001E3DE4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall func_00173ED0(Source **source);

    char unknown_04[8];
    void *ready;
    Source *source;
};

// Slot 7: gives out the object at +0x10 with a reference; S_FALSE (1) and a null result without one. E_INVALIDARG for a
// null pointer, 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E3DE4::func_00173ED0(Source **source)
{
    if (ready) {
        if (source) {
            if (this->source) {
                this->source->slot1();
                *source = this->source;
                return 0;
            }
            *source = 0;
            return 1;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
