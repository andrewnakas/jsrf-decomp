/* sym: ??0Swizzle@@QAE@KKK@Z = 0x0014EA40 */
// A 0x24-byte description that its constructor (0x14EA40) fills from a width, a height and a depth.
struct Swizzle {
    char unknown_00[0x24];

    Swizzle(unsigned long width, unsigned long height, unsigned long depth);
};

long __stdcall func_0014EAC0(Swizzle *swizzle, void *swizzled, void *linear, unsigned long bits);

// The base of the classes whose tables are at 0x1E1290 (destructor 0x152690), 0x1E1298, 0x1E12B8 and 0x1E12D8
// (created by 0x152BC0); all four share this QueryInterface.
struct Object_001E1290 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0

    void *object;
    unsigned long size;
    char unknown_0C[0x14];
    unsigned long format;
    void *data;
};

// The class whose table is at 0x1E12B8 (created by 0x152BC0).
struct Object_001E12B8 : Object_001E1290 {
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall func_00152A00();  // slot 5
};

// Hands the object at +4 and the data at +0x24 to func_0014EAC0 with a size x size x 1 description and 32 bits
// for format 4, else 16.
void __stdcall Object_001E12B8::func_00152A00()
{
    void *source = object;

    if (source) {
        Swizzle swizzle(size, size, 1);
        if (format == 4)
            func_0014EAC0(&swizzle, data, source, 0x20);
        else
            func_0014EAC0(&swizzle, data, source, 0x10);
    }
}
