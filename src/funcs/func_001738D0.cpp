struct Guid;

// The class whose table is at 0x1E3D88.
struct Object_001E3D88 {
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
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual long __stdcall func_001738D0(unsigned long *first, unsigned long *second, unsigned long *third);

    char unknown_04[8];
    void *ready;
    unsigned long first;
    unsigned long third;
    unsigned long second;
};

// Slot 21: copies the words at +0x10, +0x18 and +0x14 out, each when asked. 0x800401F0 (not initialised) while +0xc is
// null.
long __stdcall Object_001E3D88::func_001738D0(unsigned long *first, unsigned long *second, unsigned long *third)
{
    if (ready) {
        if (first)
            *first = this->first;
        if (second)
            *second = this->second;
        if (third)
            *third = this->third;
        return 0;
    }
    return 0x800401F0;
}
