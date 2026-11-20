struct Glyph_001F7088 {
    short code;
    short unknown_02;
};

extern Glyph_001F7088 data_001F7088[];

// The first glyph of each of the four ranges.
extern int data_001F8B80[4];

struct Object_0003D680 {
    int func_0003C790(int range, short code);
};

// The index of a character code among the glyphs of a range (0 to 3; range 0 runs to glyph 0x56e), or -1. Its callers
// load `this`; it does not use it.
int Object_0003D680::func_0003C790(int range, short code)
{
    int result = -1;
    int count;
    switch (range) {
    case 0:
        count = 0x56e - data_001F8B80[0];
        break;
    case 1:
        count = data_001F8B80[0] - data_001F8B80[1];
        break;
    case 2:
        count = data_001F8B80[3] - data_001F8B80[2];
        break;
    case 3:
        count = data_001F8B80[1] - data_001F8B80[3];
        break;
    }
    for (int i = 0; i < count; i++) {
        if (code == data_001F7088[data_001F8B80[range] + i].code) {
            result = data_001F8B80[range] + i;
            break;
        }
    }
    return result;
}
