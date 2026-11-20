struct Entry_0003E830 {
    char unknown_000[0xbc];
    unsigned int state;
    char unknown_0c0[4];
    int unknown_c4;
    char unknown_0c8[0x24];
    int unknown_ec;
    int unknown_f0;
    char unknown_0f4[0x18];
    Entry_0003E830 *next;
};

struct Object_0003E750 {
    char unknown_000[0x808];
    Entry_0003E830 *entries;

    int func_0003E830(int key, int);
};

// The second argument is unused; every caller pushes one (0 at 0x4bb40, 0x56990, 0x732d0).
// Counts the entries of the list at +0x808 that are free (+0xc4 clear), in state 3 or later and whose word at
// +0xec equals the key.
int Object_0003E750::func_0003E830(int key, int)
{
    int count = 0;
    for (Entry_0003E830 *entry = entries; entry; entry = entry->next) {
        if (!entry->unknown_c4 && entry->state >= 3 && entry->unknown_ec == key) {
            count++;
        }
    }
    return count;
}
