// Node child (constructor 0x24C90, destructor 0x24CF0): a page index at +0x48 and pages of 8 bit words at +0x58.
struct Object_00024CF0 {
    char unknown_00[0x48];
    int page;
    char unknown_4c[0xc];
    unsigned int bits[9][8];

    void func_00024D60(unsigned int index, int value);
};

// Sets bit `index` of the current page to `value` (0 or 1); called from slot 1 (0x25040).
void Object_00024CF0::func_00024D60(unsigned int index, int value)
{
    unsigned int word = index >> 5;
    unsigned int bit = index - (word << 5);
    bits[page][word] &= ~(1 << bit);
    bits[page][word] |= value << bit;
}
