struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

extern const Guid data_001E2168;

long __stdcall func_00166760(void *source, unsigned long flags, const Guid &id, void **result, void *reserved);

// MGameInput8, the class its factory (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings) creates; its
// table is at 0x1E1900.
struct MGameInput8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_0015FF10(void *source, void *context, void *);

    char unknown_04[8];
    void *source;
    void *context;
    char unknown_14[0x10];
    void *inner;
};

// Slot 3: creates the object of class 0x1E2168 (func_00166760, flags 0x800) into +0x24 and keeps the two values at
// +0xc and +0x10 when that works. A second call fails with 0x800401F1 (already initialised).
long __stdcall MGameInput8::func_0015FF10(void *source, void *context, void *)
{
    if (inner)
        return 0x800401F1;
    long result = func_00166760(source, 0x800, data_001E2168, &inner, 0);
    if (result >= 0) {
        this->source = source;
        this->context = context;
    }
    return result;
}
