// The shader handle at +4 of Object_001E1220.
struct Shader {
    // Writes the vertex declaration for a flexible vertex format (count streams) into declaration.
    long func_00156190(unsigned long format, unsigned long *declaration, unsigned long count);

    unsigned long handle;
};

// Writes the vertex shader declaration (Direct3D 8's D3DVSD tokens) for the flexible vertex format format, once for
// each of count streams: the stream token, then one register token a part with the registers numbered on across
// the streams: the position (three floats, four for a transformed one, with one to three blend weights or, under
// D3DFVF_LASTBETA_UBYTE4 (0x1000), packed indices as the last), the normal, the diffuse and specular colours and up
// to four sets of two texture coordinates; the end token closes it. E_INVALIDARG for an unknown position kind.
long Shader::func_00156190(unsigned long format, unsigned long *declaration, unsigned long count)
{
    unsigned long reg = 0;
    for (unsigned long stream = 0; stream < count; stream++) {
        *declaration++ = 0x20000000 | stream;
        switch (format & 0xE) {
        case 2:
            *declaration++ = reg++ | 0x40320000;
            break;
        case 4:
            *declaration++ = reg++ | 0x40420000;
            break;
        case 6:
            *declaration++ = reg++ | 0x40320000;
            if (format & 0x1000)
                *declaration++ = reg++ | 0x40440000;
            else
                *declaration++ = reg++ | 0x40120000;
            break;
        case 8:
            *declaration++ = reg++ | 0x40320000;
            if (format & 0x1000) {
                *declaration++ = reg++ | 0x40120000;
                *declaration++ = reg++ | 0x40440000;
            } else {
                *declaration++ = reg++ | 0x40220000;
            }
            break;
        case 10:
            *declaration++ = reg++ | 0x40320000;
            if (format & 0x1000) {
                *declaration++ = reg++ | 0x40220000;
                *declaration++ = reg++ | 0x40440000;
            } else {
                *declaration++ = reg++ | 0x40320000;
            }
            break;
        case 12:
            *declaration++ = reg++ | 0x40320000;
            if (format & 0x1000) {
                *declaration++ = reg++ | 0x40320000;
                *declaration++ = reg++ | 0x40440000;
            } else {
                *declaration++ = reg++ | 0x40420000;
            }
            break;
        default:
            return 0x80070057;
        }
        if (format & 0x10)
            *declaration++ = reg++ | 0x40320000;
        if (format & 0x40)
            *declaration++ = reg++ | 0x40400000;
        if (format & 0x80)
            *declaration++ = reg++ | 0x40400000;
        switch (format & 0xF00) {
        case 0x400:
            *declaration++ = reg++ | 0x40220000;
        case 0x300:
            *declaration++ = reg++ | 0x40220000;
        case 0x200:
            *declaration++ = reg++ | 0x40220000;
        case 0x100:
            *declaration++ = reg++ | 0x40220000;
        }
    }
    *declaration = 0xFFFFFFFF;
    return 0;
}
