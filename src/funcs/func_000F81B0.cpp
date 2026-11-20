// A member of Object_000F96A0 (func_000F8360 and func_000F8700 pass this in ecx; it is not read).
// Classifies the text at `text`: 1 for a lead byte 0x80-0x9f, 0 unless it starts with '$'; then by the next
// character: c 3, x 5, $ 6, r 7, e 8, v 9, j 10, s 11, n 12, p 13, b followed by c, j or o 14 to 16, a, f, m, h, o and
// g 17 to 22, anything else 2. (After "$b" and another character the result is left unset.)
struct Object_000F96A0 {
    int func_000F81B0(const char *text);
};

int Object_000F96A0::func_000F81B0(const char *text)
{
    unsigned short c = text[0] & 0xff;
    if (c >= 0x80 && c < 0xa0) {
        return 1;
    }
    int kind;
    if (c == '$') {
        switch (text[1]) {
        case 'c':
            kind = 0x3;
            break;
        case 'n':
            kind = 0xc;
            break;
        case 'r':
            kind = 0x7;
            break;
        case 'e':
            kind = 0x8;
            break;
        case '$':
            kind = 0x6;
            break;
        case 's':
            kind = 0xb;
            break;
        case 'v':
            kind = 0x9;
            break;
        case 'j':
            kind = 0xa;
            break;
        case 'x':
            kind = 0x5;
            break;
        case 'p':
            kind = 0xd;
            break;
        case 'b':
            switch (text[2]) {
            case 'c':
                kind = 0xe;
                break;
            case 'j':
                kind = 0xf;
                break;
            case 'o':
                kind = 0x10;
                break;
            }
            break;
        case 'a':
            kind = 0x11;
            break;
        case 'f':
            kind = 0x12;
            break;
        case 'm':
            kind = 0x13;
            break;
        case 'h':
            kind = 0x14;
            break;
        case 'o':
            kind = 0x15;
            break;
        case 'g':
            kind = 0x16;
            break;
        default:
            kind = 2;
            break;
        }
    } else {
        kind = 0;
    }
    return kind;
}
