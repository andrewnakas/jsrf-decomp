// What 0x155500 reads: two 12-bit values at +0 and +4 and a kind at +0x10.
struct Format {
    unsigned long first;
    unsigned long second;
    unsigned long unknown_08[2];
    unsigned long kind;
};

// Packs the two values ((first << 12 | second & 0xFFF) << 8) with 0x20 for kind 30, else 0x10 (nothing refers to
// it).
long __stdcall func_00155500(const Format *format, void *unused, unsigned long *out)
{
    unsigned long value = ((format->second & 0xfff) | format->first << 12) << 8;
    if (format->kind == 30) {
        *out = value | 0x20;
        return 0;
    }
    *out = value | 0x10;
    return 0;
}
