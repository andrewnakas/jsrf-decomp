// An entry of the id table (0xa0 bytes): kept in a bucket list (by the low byte of its id) and in one list of all
// entries; each list keeps the address of the previous link.
struct Entry_0001B400 {
    char unknown_00[0x38];
    int id;
    char unknown_3c[0x54];
    Entry_0001B400 **previous;
    Entry_0001B400 *next;
    Entry_0001B400 **allPrevious;
    Entry_0001B400 *allNext;
};

struct Object_00016200 {
    char unknown_0000[0x890];
    Entry_0001B400 *heads[0x100];
    Entry_0001B400 **tails[0x100];
    Entry_0001B400 *allHead;
    Entry_0001B400 **allTail;

    void func_0001B400(int id);
};

// Finds the entry with the id in its bucket, unlinks it from its bucket and from the list of all entries, and frees it.
void Object_00016200::func_0001B400(int id)
{
    unsigned int bucket = id & 0xff;
    for (Entry_0001B400 *entry = heads[bucket]; entry; entry = entry->next) {
        if (entry->id == id) {
            if (entry->previous) {
                *entry->previous = entry->next;
                if (entry->next)
                    entry->next->previous = entry->previous;
                else
                    tails[bucket] = entry->previous;
            }
            if (entry->allPrevious) {
                *entry->allPrevious = entry->allNext;
                if (entry->allNext)
                    entry->allNext->allPrevious = entry->allPrevious;
                else
                    allTail = entry->allPrevious;
            }
            delete entry;
            return;
        }
    }
}
