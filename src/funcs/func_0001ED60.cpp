// A list of ranges: the count at +0x34, the low ends (+0x3c) and high ends (+0x40).
struct Ranges_0001ED60 {
    char unknown_00[0x34];
    unsigned int count;
    char unknown_38[4];
    unsigned int *lows;
    unsigned int *highs;
};

struct Entry_0001ED60 {
    char unknown_00[8];
    Ranges_0001ED60 *ranges;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990).
struct Object_00022990 {
    char unknown_00[0xe0];
    Entry_0001ED60 **entries;

    unsigned int func_0001ED60(unsigned int index, unsigned int value, int *found);
};

// Called by func_0001F450: the indices of the first two ranges of entry `index` (+0x8) that hold `value`, into
// `found` (-1 for none). Returns how many were found.
unsigned int Object_00022990::func_0001ED60(unsigned int index, unsigned int value, int *found)
{
    Ranges_0001ED60 *ranges = entries[index]->ranges;
    if (ranges->count <= 0)
        return 0;
    found[1] = -1;
    found[0] = -1;
    unsigned int n = 0;
    for (unsigned int i = 0; i < ranges->count && n < 2; i++) {
        if (ranges->lows[i] <= value && value <= ranges->highs[i])
            found[n++] = i;
    }
    return n;
}
