extern int data_0021C4B0[];

// An entry of the list at +0x1658: a key, three pointers at +0x1c, the next entry at +0x2c.
struct Entry_00033C10 {
    int key;
    char unknown_04[0x18];
    void *values[3];
    int unknown_28;
    Entry_00033C10 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1658];
    Entry_00033C10 *entries;

    void *func_00033C10(int kind, int unused, unsigned int index);
};

// Handler 16 of the table at 0x1EC200: pointer `index` (below 3) of the entry whose key the table at 0x21C4B0 gives
// for a kind; 0 without one.
void *Object_000265A0::func_00033C10(int kind, int, unsigned int index)
{
    int key = data_0021C4B0[kind];
    for (Entry_00033C10 *entry = entries; entry; entry = entry->next) {
        if (entry->key == key && index < 3) {
            return entry->values[index];
        }
    }
    return 0;
}
