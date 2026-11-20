struct Guid;

// Two words read and written together.
struct Pair {
    unsigned long low;
    unsigned long high;
};

// The class whose table is at 0x1E3F84: one of the classes the MFile2 factory (0x1E3F1C) creates (func_00176280
// builds it). The table at 0x1E406C holds the same function in this slot.
struct Object_001E3F84 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall func_00179210(const Pair *position);

    char unknown_04[8];
    void *file;
    Pair position;
};

// Slot 9: keeps the two words at +0x10. Fails with 0x800401F0 (not initialised) while the handle at +0xc is -1, and
// with E_INVALIDARG for a null pointer.
long __stdcall Object_001E3F84::func_00179210(const Pair *position)
{
    if (file != (void *)-1) {
        if (position) {
            this->position.low = position->low;
            this->position.high = position->high;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
