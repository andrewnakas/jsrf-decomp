// The first codes of the five glyph ranges.
extern unsigned short data_001F8B70[5];

struct Object_0003D680 {
    int func_0003C730(unsigned short code);
};

// The range a character code falls in by the first codes at 0x1F8B70: -1 below the first, 0 to 3 between them, 4 at
// or above the last. Its callers load `this`; it does not use it.
int Object_0003D680::func_0003C730(unsigned short code)
{
    if (code < data_001F8B70[0])
        return -1;
    if (code < data_001F8B70[1])
        return 0;
    if (code < data_001F8B70[2])
        return 1;
    if (code < data_001F8B70[3])
        return 2;
    return code < data_001F8B70[4] ? 3 : 4;
}
