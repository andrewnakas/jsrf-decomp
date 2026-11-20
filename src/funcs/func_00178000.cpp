struct Guid;

// The objects the class holds.
struct Held {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The class whose table is at 0x1E4020: one of the classes the MFile2 factory (0x1E3F1C) creates.
struct Object_001E4020 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    void func_00178000();

    char unknown_04[8];
    Held *first;
    Held *second;
    Held *unknown_14;
    Held *unknown_18;
    Held *unknown_1c;
    Held *unknown_20;
};

// Lets go of the objects at +0x14, +0x20, +0x18, +0x1c, +0x10 and +0xc, in that order (its destructor and slot 17
// call it).
void Object_001E4020::func_00178000()
{
    if (unknown_14) {
        unknown_14->slot2();
        unknown_14 = 0;
    }
    if (unknown_20) {
        unknown_20->slot2();
        unknown_20 = 0;
    }
    if (unknown_18) {
        unknown_18->slot2();
        unknown_18 = 0;
    }
    if (unknown_1c) {
        unknown_1c->slot2();
        unknown_1c = 0;
    }
    if (second) {
        second->slot2();
        second = 0;
    }
    if (first) {
        first->slot2();
        first = 0;
    }
}
