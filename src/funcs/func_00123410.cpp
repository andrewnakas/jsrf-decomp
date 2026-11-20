struct Object_00120420 {
    char unknown_0000[0x10ec];
    int kind;
    char unknown_10f0[0x24];
    int base;
    char unknown_1118[2];
    unsigned short first;
    unsigned short second;

    int func_00123410();
};

// An index from the base at +0x1114: -1 for a negative base, base + 36 * first for kind 0, base + 0xb4 +
// 58 * second for kind 1, and base + 0xee otherwise.
int Object_00120420::func_00123410()
{
    if (base < 0) {
        return -1;
    }
    if (kind == 0) {
        return base + first * 36;
    }
    if (kind == 1) {
        return base + 0xb4 + second * 0x3a;
    }
    return base + 0xee;
}
