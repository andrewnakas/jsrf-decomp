extern "C" void *__cdecl memcpy(void *destination, const void *source, unsigned int size);

struct Guid;

// The class whose table is at 0x1E2008.
struct Object_001E2008 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall func_00165C70(const void *data);

    long __stdcall func_001656D0();
    long __stdcall func_001659E0();
    long __stdcall func_00165AB0();

    char unknown_04[0x10];
    char data[0x900];
    unsigned long size;
    char unknown_918[0xc];
    unsigned char kind;
};

// Slot 5: copies the data in to +0x14 (the size at +0x914) and runs 0x165AB0, 0x1659E0 or 0x1656D0 by the kind byte at
// +0x924 (0x12, 0x13, any other). E_INVALIDARG for a null pointer.
long __stdcall Object_001E2008::func_00165C70(const void *data)
{
    if (data) {
        memcpy(this->data, data, size);
        switch (kind) {
        case 0x12:
            return func_00165AB0();
        case 0x13:
            return func_001659E0();
        default:
            return func_001656D0();
        }
    }
    return 0x80070057;
}
