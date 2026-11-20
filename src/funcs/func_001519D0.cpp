extern char data_00264D68[];
int func_00145CCB(char *buffer, const char *format, ...);

// A class whose table is at 0x1E1248 (9 slots; Release 0x151C40, created by 0x151CA0).
struct Object_001E1248 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(unsigned long x, unsigned long y, const char *text);
    virtual long __stdcall func_001519D0(unsigned long x, unsigned long y, int number);  // slot 5
};

// Formats the number as "%d" into the buffer at 0x264D68 and passes it to slot 4.
long __stdcall Object_001E1248::func_001519D0(unsigned long x, unsigned long y, int number)
{
    func_00145CCB(data_00264D68, "%d", number);
    return slot4(x, y, data_00264D68);
}
