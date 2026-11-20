// Draws one 24 x 24 glyph (hand-written, SSE): destination, glyph bits, the expansion table and the pitch.
void __fastcall func_0015A170(unsigned char *destination, const unsigned char *glyph, const unsigned short (*table)[8],
                              unsigned long pitch);

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
    virtual void __stdcall func_0015A1C0(unsigned long x, unsigned long y, const unsigned short *text);  // slot 9

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

// Sets the 16-bit pixels of out (eight of them) whose bits are set in bits, the highest bit first.
static inline void Row8(unsigned short *out, unsigned int bits, unsigned short color)
{
    if (bits) {
        if (bits & 0x80)
            out[0] = color;
        if (bits & 0x40)
            out[1] = color;
        if (bits & 0x20)
            out[2] = color;
        if (bits & 0x10)
            out[3] = color;
        if (bits & 8)
            out[4] = color;
        if (bits & 4)
            out[5] = color;
        if (bits & 2)
            out[6] = color;
        if (bits & 1)
            out[7] = color;
    }
}

// Slot 9: draws the zero-terminated text (glyph numbers, 0x48 bytes of 1-bit 24 x 24 glyph each) at x, y of the
// picture, 24 pixels a character: through func_0015A170 and the table of 256 x 8 pixels (16-byte aligned inside
// the object, filled by slot 5) normally, in the table's single colour when +0x1038 is set.
void __stdcall Object_001E141C::func_0015A1C0(unsigned long x, unsigned long y, const unsigned short *text)
{
    unsigned char *line = pixels + pitch * y + x * 2;
    if (!plain) {
        for (unsigned short c = *text; c; c = *++text) {
            func_0015A170(line, glyphs + c * 0x48, table, pitch);
            line += 0x30;
        }
    } else {
        unsigned int color = table[1][7];
        for (unsigned short c = *text; c; c = *++text) {
            const unsigned char *glyph = glyphs + c * 0x48;
            unsigned char *row = line;
            for (int count = 0x18; count; count--) {
                Row8((unsigned short *)row, glyph[0], color);
                Row8((unsigned short *)row + 8, glyph[1], color);
                Row8((unsigned short *)row + 16, glyph[2], color);
                row += pitch;
                glyph += 3;
            }
            line += 0x30;
        }
    }
}
