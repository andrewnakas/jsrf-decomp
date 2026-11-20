int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Part_000338C0 {
    virtual ~Part_000338C0();
};

// An entry of the list at +0x1c4 (0x14 bytes).
struct Entry_000365C0 {
    int key;
    Part_000338C0 *part;
    void *buffer;
    Entry_000365C0 **link;
    Entry_000365C0 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1c4];
    Entry_000365C0 *entries;
    Entry_000365C0 **tail;

    void func_000365C0(int key);
};

// Handler 3 of the table at 0x1EC288: deletes the entry with `key` from the list at +0x1c4 (tail link at +0x1c8),
// with its part (virtual destructor) and its memory (func_00145A5D with 0x8000).
void Object_000265A0::func_000365C0(int key)
{
    for (Entry_000365C0 *entry = entries; entry; entry = entry->next) {
        if (entry->key == key) {
            if (entry->part)
                delete entry->part;
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
