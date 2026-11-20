void __cdecl operator delete(void *memory) throw();

// An entry of the list at 0x20C750 (0x190 bytes): a block at +0, its key at +0x178, the link that points at it
// (+0x188) and the next entry (+0x18c).
struct Entry_0006CD80 {
    void *block;
    char unknown_004[0x174];
    int key;
    char unknown_17c[0xc];
    Entry_0006CD80 **link;
    Entry_0006CD80 *next;
};

// The list at 0x20C750.
struct Object_000149B0 {
    char unknown_00[4];
    Entry_0006CD80 *head;
    Entry_0006CD80 **tail;

    void func_0006CD80(int key);
};

// Called by the destructor 0x6CE00: unlinks and frees the first entry with the key, and its block.
void Object_000149B0::func_0006CD80(int key)
{
    for (Entry_0006CD80 *entry = head; entry; entry = entry->next) {
        if (entry->key == key) {
            if (entry->block) {
                operator delete(entry->block);
            }
            *entry->link = entry->next;
            if (entry->next) {
                entry->next->link = entry->link;
            } else {
                tail = entry->link;
            }
            operator delete(entry);
            return;
        }
    }
}
