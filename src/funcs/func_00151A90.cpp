#include "stdarg.h"

extern char data_00264D68[];
int __stdcall func_00145CB4(char *buffer, const char *format, va_list args);

// A class whose table is at 0x1E1248 (9 slots; Release 0x151C40, created by 0x151CA0).
struct Object_001E1248 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(unsigned long x, unsigned long y, const char *text);
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual long func_00151A90(unsigned long x, unsigned long y, const char *format, ...);  // slot 8
};

// Formats the arguments into the buffer at 0x264D68 with func_00145CB4 and passes it to slot 4.
long Object_001E1248::func_00151A90(unsigned long x, unsigned long y, const char *format, ...)
{
    va_list args;

    va_start(args, format);
    func_00145CB4(data_00264D68, format, args);
    return slot4(x, y, data_00264D68);
}
