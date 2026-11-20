// A class whose table is at 0x1E141C (12 slots; Release 0x1579A0): text drawn into a 16-bit picture.
struct Object_001E141C {
    virtual long __stdcall func_001577C0(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001576F0();  // slot 1
    virtual unsigned long __stdcall func_001579A0();  // slot 2
    virtual long __stdcall func_00157800(unsigned long first, unsigned long second, unsigned long third);  // slot 3
    virtual void __stdcall func_00157960();  // slot 4
    virtual long __stdcall func_00157100(unsigned long first, unsigned long second);  // slot 5
    virtual long __stdcall func_001571E0(unsigned long first, unsigned long second);  // slot 6
    virtual long __stdcall func_001572D0();  // slot 7
    virtual long __stdcall func_00157300();  // slot 8

    unsigned long buffer[0x404];
    unsigned long value_1014;
    unsigned long value_1018;
    unsigned long value_101C;
    float value_1020;
    unsigned short (*table)[8];
    unsigned char *glyphs;
    unsigned long value_102C;
    unsigned char *pixels;
    unsigned long pitch;
    unsigned long plain;
    unsigned long references;
};

// Slot 5: fills the expansion table for color (0xAARRGGBB, made 1-5-5-5 with the top bit set): entry i holds the
// eight pixels of the bits of i, the colour where a bit is set and 0 elsewhere. Bit 0 of flags selects the
// single-colour drawing of slot 9 (+0x1038).
long __stdcall Object_001E141C::func_00157100(unsigned long color, unsigned long flags)
{
    unsigned short pixel = (unsigned short)((color >> 9 & 0xFC00) | (color >> 6 & 0x3E0) | (color >> 3 & 0x1F) | 0x8000);
    unsigned short (*entry)[8] = table;
    for (unsigned int bits = 0; bits < 0x100; bits++) {
        (*entry)[0] = bits & 0x80 ? pixel : 0;
        (*entry)[1] = bits & 0x40 ? pixel : 0;
        (*entry)[2] = bits & 0x20 ? pixel : 0;
        (*entry)[3] = bits & 0x10 ? pixel : 0;
        (*entry)[4] = bits & 8 ? pixel : 0;
        (*entry)[5] = bits & 4 ? pixel : 0;
        (*entry)[6] = bits & 2 ? pixel : 0;
        (*entry)[7] = bits & 1 ? pixel : 0;
        entry++;
    }
    plain = flags & 1;
    return 0;
}
