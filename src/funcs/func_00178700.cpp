struct Guid;

// The class whose table is at 0x1E4020.
struct Object_001E4020 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(unsigned __int64 *position);
    virtual long __stdcall slot7(unsigned __int64 *length);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual long __stdcall func_00178700(void *argument);
    virtual long __stdcall slot15(int argument);

    char unknown_04[8];
    void *first;
    void *second;
};

// Slot 14: gives out status flags: 2 when slot 15 answers 0x8000000A, 1 when the position (slot 6) has reached the
// length (slot 7). Returns the first failure, else the result of slot 6. E_INVALIDARG for a null pointer, 0x800401F0
// (not initialised) while +0xc and +0x10 are both null.
long __stdcall Object_001E4020::func_00178700(void *argument)
{
    if (second || first) {
        unsigned long *status = (unsigned long *)argument;
        if (status) {
            *status = 0;
            long result = slot15(0);
            if (result == 0x8000000A)
                *status |= 2;
            else if (result < 0)
                return result;
            unsigned __int64 position;
            unsigned __int64 length;
            result = slot7(&length);
            if (result < 0)
                return result;
            result = slot6(&position);
            if (result < 0)
                return result;
            if (position >= length)
                *status |= 1;
            return result;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
