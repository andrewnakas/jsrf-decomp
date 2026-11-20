extern "C" void *memset(void *destination, int value, unsigned int size);

void *func_00025700(unsigned int index, int first, int second, int third);

// An entry of the list at +0x1ac (0x18 bytes; func_00030750 reads its lists).
struct Entry_00030690 {
    int key;
    int unknown_04;
    Entry_00030690 *next;
    void **first;
    void **second;
    int unknown_14;
};

struct Result_00030690 {
    char unknown_000[0x21c];
    int unknown_21c;
};

struct Object_000265A0 {
    char unknown_0000[0x1ac];
    Entry_00030690 *entries;
    char unknown_01b0[4];
    Entry_00030690 *entry;
    int unknown_1b8;
    int key;
    int unknown_1c0;

    int func_00030690(int key);
};

// Handler 29 of the table at 0x1EC068: 0 when the list at +0x1ac already holds `key`; otherwise clears +0x1b8 and
// +0x1c0, keeps the key at +0x1bc and a new cleared entry at +0x1b4; when func_00025700 (0, key, 0, 0) gives a result,
// copies its +0x21c into the entry's +0x14 and returns 1, else 0.
int Object_000265A0::func_00030690(int key)
{
    for (Entry_00030690 *item = entries; item; item = item->next) {
        if (item->key == key)
            return 0;
    }
    unknown_1b8 = 0;
    this->key = key;
    unknown_1c0 = 0;
    entry = new Entry_00030690;
    memset(entry, 0, sizeof(Entry_00030690));
    Result_00030690 *result = (Result_00030690 *)func_00025700(0, key, 0, 0);
    if (result) {
        entry->unknown_14 = result->unknown_21c;
        return 1;
    }
    return 0;
}
