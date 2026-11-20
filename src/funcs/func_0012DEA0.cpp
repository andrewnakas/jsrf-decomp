struct Sizes_0012DEA0 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
};

struct Object_00120420 {
    char unknown_000[0x438];
    unsigned long availableLow;
    unsigned long availableHigh;

    int func_0012DEA0(int kind, int other);
};

extern Sizes_0012DEA0 data_002285B8[];

// Whether the free space at +0x438 holds what a kind needs (its four sizes and 0xc494 bytes), counting the space
// another kind (0 to 4, its sizes and 0xc37c bytes) would give back. 0 for an other kind above 4.
int Object_00120420::func_0012DEA0(int kind, int other)
{
    if (other > 4) {
        return 0;
    }
    unsigned int need = data_002285B8[kind].a + data_002285B8[kind].b + data_002285B8[kind].c + data_002285B8[kind].d + 0xc494;
    unsigned int back;
    if (other < 0) {
        back = 0;
    } else {
        back = data_002285B8[other].a + data_002285B8[other].b + data_002285B8[other].c + data_002285B8[other].d + 0xc37c;
    }
    if (availableHigh > 0) {
        return 1;
    }
    if (availableLow >= need) {
        return 1;
    }
    return availableLow + back >= need;
}
