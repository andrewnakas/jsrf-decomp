struct Guid;

// The class whose table is at 0x1E3C80.
struct Object_001E3C80 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00172820(void *handle);

    char unknown_04[8];
    void *handle;
};

// Slot 3: takes a handle once. A second call fails with 0x800401F1 (already initialised), a null handle with
// E_INVALIDARG.
long __stdcall Object_001E3C80::func_00172820(void *handle)
{
    if (this->handle)
        return 0x800401F1;
    if (handle) {
        this->handle = handle;
        return 0;
    }
    return 0x80070057;
}
