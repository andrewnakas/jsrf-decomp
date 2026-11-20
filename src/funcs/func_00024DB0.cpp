// Node child (constructor 0x24C90, destructor 0x24CF0): a page index at +0x48, pages of 8 bit words at +0x58 and
// the number of bits in use at +0x17c.
struct Object_00024CF0 {
    char unknown_000[0x48];
    int page;
    char unknown_04c[0xc];
    unsigned int bits[9][8];
    char unknown_178[4];
    unsigned int count;

    int func_00024DB0();
};

// 1 when the first `count` bits of the current page are all set: the last word against its mask, then the words
// before it. The loop over those steps upward from the word before the last, as retail does.
int Object_00024CF0::func_00024DB0()
{
    unsigned int word = (count - 1) >> 5;
    unsigned int bit = count - (word << 5) - 1;
    if (((((1 << bit) - 1) << 1) | 1) != bits[page][word])
        return 0;
    for (int i = word - 1; i >= 0; i++) {
        if (bits[page][i] != 0xffffffff)
            return 0;
    }
    return 1;
}
