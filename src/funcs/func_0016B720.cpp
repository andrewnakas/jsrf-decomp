struct Guid;

// The class whose table is at 0x1E3B90 (30 slots; the destructor is the last).
struct Object_001E3B90 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall slot7(void *settings);
    virtual void slot8();
    virtual void slot9();
    virtual long __stdcall slot10(unsigned long value);
    virtual long __stdcall slot11(unsigned long value);
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual long __stdcall slot23(unsigned long value);

    long __stdcall func_0016B720();

    char unknown_04[8];
    void *device;
    char unknown_10[0x24];
    char settings[4];
    void *settingsSet;
    char unknown_3c[0x210];
    unsigned long pending1;
    unsigned long pending2;
    unsigned long pending3;
    char unknown_258[0x2c];
    unsigned long caps;
};

// Not referenced: applies the settings kept while there was no device. Slot 7 with the block at +0x34 when +0x38 is
// set (its result is dropped), then slots 10, 11 and (with caps bit 1) 23 with each word at +0x24c, +0x250 and +0x254
// whose top bit marks a pending value. 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E3B90::func_0016B720()
{
    long result;
    if (device) {
        result = 0;
        if (settingsSet)
            slot7(settings);
        if (pending1 & 0x80000000)
            result = slot10(pending1 & 0x7fffffff);
        if (pending2 & 0x80000000)
            result = slot11(pending2 & 0x7fffffff);
        if ((caps & 1) && (pending3 & 0x80000000))
            result = slot23(pending3 & 0x7fffffff);
    } else {
        result = 0x800401F0;
    }
    return result;
}
