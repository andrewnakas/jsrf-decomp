struct Entry_0006EA40 {
    int unknown_00;
    unsigned int first;
    unsigned int second;
    unsigned int third;
};

struct Header_0006EA40 {
    char unknown_00;
    unsigned char count;
    char unknown_02[2];
    Entry_0006EA40 *entries;
};

// Turns the offsets of a block loaded from disk into pointers: the entry table at +4 and the three words after the
// first of each of its `count` 16-byte entries. Its callers push the block and load no object: __stdcall.
void __stdcall func_0006EA40(Header_0006EA40 *header)
{
    header->entries = (Entry_0006EA40 *)((unsigned int)header->entries + (unsigned int)header);
    Entry_0006EA40 *entry = header->entries;
    for (unsigned int i = 0; i < header->count; i++, entry++) {
        entry->first += (unsigned int)header;
        entry->second += (unsigned int)header;
        entry->third += (unsigned int)header;
    }
}
