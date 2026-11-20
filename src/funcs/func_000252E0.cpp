struct Entry_000252E0 {
    unsigned int data;
    Entry_000252E0 *next;
};

struct Block_000252E0 {
    int unknown_00;
    unsigned int count;
    char unknown_08[8];
    Entry_000252E0 first;
};

// Turns the offsets of a block loaded from disk into pointers: for each of its `count` entries, from the one at +0x10,
// adds the block's address to the data and next words and follows next.
void func_000252E0(Block_000252E0 *block)
{
    Entry_000252E0 *entry = &block->first;
    for (unsigned int i = 0; i < block->count; i++) {
        entry->data += (unsigned int)block;
        entry->next = (Entry_000252E0 *)((unsigned int)entry->next + (unsigned int)block);
        entry = entry->next;
    }
}
