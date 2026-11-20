struct Glyph_001F7088 {
    short code;
    short unknown_02;
};

extern Glyph_001F7088 data_001F7088[];
extern int data_001F8B88;

struct Object_0003D370 {
    int func_0003C830(short code);
};

// The index of a character code among the data_001F8B88 glyphs at 0x1F7088, or -1.
int Object_0003D370::func_0003C830(short code)
{
    int found = -1;
    for (int i = 0; i < data_001F8B88; i++) {
        if (code == data_001F7088[i].code) {
            found = i;
            break;
        }
    }
    return found;
}
