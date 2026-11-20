struct Guid;

// The class whose table is at 0x1E3C08 (30 slots, the same Release as 0x1E3B90).
struct Object_001E3C08 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall slot9(unsigned long *flags);
    virtual long __stdcall slot10(unsigned long how);
    virtual long __stdcall slot11(unsigned long how);
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual long __stdcall func_0016FFE0(int start);

    char unknown_04[0xc];
    void *ready;
    char unknown_14[0xdc];
    unsigned long state;
};

// Slot 19: reads the flags (slot 9). To start: when +0xf0 has no bit 1 and the flags have it, calls slot 11 with 0 and
// keeps the flags at +0xf0. To stop: when +0xf0 has bit 1, calls slot 10 with 2 (bit 4 set) or 0 and clears +0xf0.
// 0x800401F0 (not initialised) while +0x10 is null.
long __stdcall Object_001E3C08::func_0016FFE0(int start)
{
    if (ready) {
        unsigned long flags;
        slot9(&flags);
        if (start) {
            if (!(state & 1) && (flags & 1)) {
                slot11(0);
                state = flags;
            }
        } else if (state & 1) {
            if (state & 4)
                slot10(2);
            else
                slot10(0);
            state = 0;
        }
        return 0;
    }
    return 0x800401F0;
}
