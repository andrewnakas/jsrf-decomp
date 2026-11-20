// 0x9c 8-byte records at 0x1F8640, each starting with a character code.
struct Record_001F8640 {
    short code;
    unsigned short unknown_02;
    short unknown_04;
    short unknown_06;
};

extern Record_001F8640 data_001F8640[0x9c];

struct Object_0003D680 {
    int func_0003C860(int guess, short code);
};

// The index of the record holding a character code, searching outward from `guess` (above it first), or -1. Its
// callers load `this`; it does not use it.
int Object_0003D680::func_0003C860(int guess, short code)
{
    int result = -1;
    for (int i = 0; i < 0x9c; i++) {
        if (guess + i < 0x9c && code == data_001F8640[guess + i].code) {
            result = guess + i;
            break;
        }
        if (guess - i > 0 && code == data_001F8640[guess - i].code) {
            result = guess - i;
            break;
        }
    }
    return result;
}
