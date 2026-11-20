struct Entry_0003E830 {
    char unknown_000[0x98];
    unsigned int slots;
    char unknown_09c[8];
    unsigned int bits_a4;
    char unknown_0a8[4];
    unsigned int bits_ac;
    char unknown_0b0[0xc];
    unsigned int state;
    char unknown_0c0[4];
    int unknown_c4;
    char unknown_0c8[0x44];
    Entry_0003E830 *next;
};

struct Object_0003E750 {
    char unknown_000[0x808];
    Entry_0003E830 *entries;

    int func_0003E760();
    int func_0003E7A0(int second);
};

// Counts the entries of the list at +0x808 that are free (+0xc4 clear) and in state 3 or later.
int Object_0003E750::func_0003E760()
{
    int count = 0;
    for (Entry_0003E830 *entry = entries; entry; entry = entry->next) {
        if (!entry->unknown_c4 && entry->state >= 3) {
            count++;
        }
    }
    return count;
}
