struct Entry_0002C2D0 {
    int key;
    void **first;
    char unknown_08[4];
    void **second;
    char unknown_10[0xc];
    void **third;
    char unknown_20[4];
    void **fourth;
    char unknown_28[4];
    void **fifth;
    char unknown_30[0xc];
    Entry_0002C2D0 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1724];
    Entry_0002C2D0 *entries;

    void *func_0002C2D0(int key, int kind, int index);
};

// Handler 18 of the table at 0x1EC200: pointer `index` of one of five lists (+0x4, +0xc, +0x1c, +0x24, +0x2c) of
// the entry with `key` in the list at +0x1724, by kind; 0 otherwise.
void *Object_000265A0::func_0002C2D0(int key, int kind, int index)
{
    for (Entry_0002C2D0 *entry = entries; entry; entry = entry->next) {
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
            case 4:
                return entry->fifth[index];
            }
        }
    }
    return 0;
}
