char *func_0017D561(double value, int digits, char *buffer);

extern char data_00264D68[];

// A class whose table is at 0x1E1248 (9 slots; Release 0x151C40, created by 0x151CA0).
struct Object_001E1248 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(unsigned long x, unsigned long y, const char *text);
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual long __stdcall func_00151A30(unsigned long x, unsigned long y, float value);  // slot 7
};

// Writes the value with six digits (func_0017D561) into the buffer at 0x264D68 and passes it to slot 4.
long __stdcall Object_001E1248::func_00151A30(unsigned long x, unsigned long y, float value)
{
    char text[32];
    char *out;
    const char *in;

    func_0017D561(value, 6, text);
    out = data_00264D68;
    in = text;
    while (*in)
        *out++ = *in++;
    *out = 0;
    return slot4(x, y, data_00264D68);
}
