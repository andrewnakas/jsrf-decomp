struct Entry_000355C0 {
    int key;
    void **first;
    char unknown_08[0xc];
    void **second;
    char unknown_18[4];
    void **third;
    char unknown_20[4];
    void **fourth;
    char unknown_28[0xc];
    Entry_000355C0 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1680];
    Entry_000355C0 *entries;

    void *func_000355C0(int key, int kind, int index);
};

// Handler 15 of the table at 0x1EC200: pointer `index` of the first (+0x4), second (+0x14), third (+0x1c) or fourth
// (+0x24) list of the entry with `key` in the list at +0x1680, by kind; 0 otherwise.
void *Object_000265A0::func_000355C0(int key, int kind, int index)
{
    for (Entry_000355C0 *entry = entries; entry; entry = entry->next) {
        if (entry->key == key) {
            switch (kind) {
            case 0:
                return entry->first[index];
            case 1:
                return entry->second[index];
            case 2:
                return entry->third[index];
            case 3:
                return entry->fourth[index];
            }
        }
    }
    return 0;
}
