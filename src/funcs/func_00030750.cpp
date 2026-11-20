struct Entry_00030750 {
    int key;
    int unknown_04;
    Entry_00030750 *next;
    void **first;
    void **second;
};

struct Object_000265A0 {
    char unknown_0000[0x1ac];
    Entry_00030750 *entries;

    void *func_00030750(int key, int kind, int index);
};

// Handler 29 of the table at 0x1EC200: pointer `index` of the first (+0xc, kind 0) or second (+0x10, kind 1) list of the
// entry with `key` in the list at +0x1ac; 0 otherwise.
void *Object_000265A0::func_00030750(int key, int kind, int index)
{
    for (Entry_00030750 *entry = entries; entry; entry = entry->next) {
        if (entry->key == key) {
            switch (kind) {
            case 0:
                return entry->first[index];
            case 1:
                return entry->second[index];
            }
        }
    }
    return 0;
}
