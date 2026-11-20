void *operator new(unsigned int size);

// One slot of a ring of free entries (0x10 bytes): unset (-1) until used, and the next slot.
struct Entry_000C5EA0 {
    int key;
    int unknown_04[2];
    Entry_000C5EA0 *next;
};

// The owner at 0x4 of the Object_000CC600 family.
struct Object_000C5B50 {
    Entry_000C5EA0 *func_000C5EA0(unsigned int count);
};

// Allocates count entries, marks each unset (-1) and links them into a ring; returns the first.
Entry_000C5EA0 *Object_000C5B50::func_000C5EA0(unsigned int count)
{
    Entry_000C5EA0 *entries = (Entry_000C5EA0 *)operator new(count * sizeof(Entry_000C5EA0));
    Entry_000C5EA0 *entry = entries;
    for (unsigned int i = 0; i < count - 1; i++) {
        entry->key = -1;
        entry->next = entry + 1;
        entry = entry + 1;
    }
    entry->key = -1;
    entry->next = entries;
    return entries;
}
