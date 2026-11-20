struct Guid;

// The objects the class holds at +0xc to +0x20 (slot 2 lets go of one).
struct Held {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(int argument);
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
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual long __stdcall slot15(int);
    virtual long __stdcall func_001786B0();

    char unknown_04[8];
    Held *first;
    Held *second;
    Held *unknown_14;
    Held *unknown_18;
    Held *unknown_1c;
    Held *unknown_20;
    char unknown_24[0xc];
    unsigned char flags;
};

// Finishes the pending transfer (0x178180).
long __stdcall func_00178180(Object_001E4020 *self);

// Slot 16: with flag 0x80 at +0x30, asks slot 15 with 0 and, when that gives 0x8000000A (still pending), finishes the
// transfer (0x178180) and asks again; otherwise calls slot 6 of the object at +0x20 with 0 first. 0x800401F0 (not
// initialised) without that object.
long __stdcall Object_001E4020::func_001786B0()
{
    if (unknown_20) {
        if (flags & 0x80) {
            long result = slot15(0);
            if (result != 0x8000000A)
                return result;
            func_00178180(this);
            return slot15(0);
        }
        unknown_20->slot6(0);
        return slot15(0);
    }
    return 0x800401F0;
}
