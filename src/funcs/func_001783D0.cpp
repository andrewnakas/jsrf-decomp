struct Guid;

// The two objects the class passes its calls on to.
struct First {
    virtual void slot0();
};

struct Second {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual long __stdcall slot8(char *text, void *argument);
};

// The class whose table is at 0x1E4020: one of the classes the MFile2 factory (0x1E3F1C) creates (func_00176460
// builds it).
struct Object_001E4020 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual long __stdcall func_001783D0(char *text, void *argument);

    char unknown_04[8];
    First *first;
    Second *second;
};

// Slot 8: with an object at +0xc, empties the text and returns S_FALSE (E_INVALIDARG for a null argument); otherwise
// passes both arguments on to slot 8 of the object at +0x10 (a tail call), or fails with 0x800401F0 (not initialised).
long __stdcall Object_001E4020::func_001783D0(char *text, void *argument)
{
    if (first) {
        if (text && argument) {
            *text = 0;
            return 1;
        }
        return 0x80070057;
    }
    if (second)
        return second->slot8(text, argument);
    return 0x800401F0;
}
