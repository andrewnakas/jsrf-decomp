struct Entry_00012A20 {
    char unknown_00[0x14];
    unsigned int key;
    char unknown_18[0x28];
    Entry_00012A20 *next;
};

struct Game {
    char unknown_0000[0x7fac];
    Entry_00012A20 *entries;
    Entry_00012A20 **entryTail;
    Entry_00012A20 *buckets[0x100];
    Entry_00012A20 **tails[0x100];

    void func_00012A20(int shift);
};

// Sorts the game's list of entries by a byte of their keys (+0x14, shifted right by `shift`): deals them into 256
// chains, then joins the chains back into the list from the last one down.
void Game::func_00012A20(int shift)
{
    int i;
    for (i = 0; i < 0x100; i++) {
        buckets[i] = 0;
        tails[i] = &buckets[i];
    }
    Entry_00012A20 *entry = entries;
    while (entry) {
        int index = (entry->key >> shift) & 0xff;
        *tails[index] = entry;
        Entry_00012A20 **link = &entry->next;
        entry = *link;
        *link = 0;
        tails[index] = link;
    }
    entries = 0;
    entryTail = &entries;
    for (i = 0xff; i >= 0; i--) {
        if (buckets[i]) {
            *entryTail = buckets[i];
            entryTail = tails[i];
        }
    }
}
