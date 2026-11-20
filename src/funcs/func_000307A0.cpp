int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

// The 16-byte item func_00030490 creates at +0x1a0.
struct Item_00030490 {
    int unknown_00;
    void *buffer;
    int unknown_08;
    int unknown_0c;
};

// An entry of the list at +0x198 (16 bytes).
struct Entry_000307A0 {
    int key;
    void *buffer;
    Entry_000307A0 **link;
    Entry_000307A0 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x198];
    Entry_000307A0 *entries;
    Entry_000307A0 **tail;
    Item_00030490 *item;

    void func_000307A0(int key);
};

// Handler 0 of the table at 0x1EC288: deletes the item at +0x1a0 with its memory (func_00145A5D with 0x8000), then the
// entry with `key` from the list at +0x198 (tail link at +0x19c) with its memory.
void Object_000265A0::func_000307A0(int key)
{
    if (item) {
        if (item->buffer)
            func_00145A5D(item->buffer, 0, 0x8000);
        delete item;
        item = 0;
    }
    for (Entry_000307A0 *entry = entries; entry; entry = entry->next) {
        if (entry->key == key) {
            if (entry->buffer)
                func_00145A5D(entry->buffer, 0, 0x8000);
            *entry->link = entry->next;
            if (entry->next)
                entry->next->link = entry->link;
            else
                tail = entry->link;
            delete entry;
            return;
        }
    }
}
