extern "C" void *memset(void *destination, int value, unsigned int size);

struct Entry_00030490 {
    int key;
    char unknown_04[8];
    Entry_00030490 *next;
};

struct Item_00030490 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
};

struct Object_000265A0 {
    char unknown_0000[0x198];
    Entry_00030490 *entries;
    char unknown_019c[4];
    Item_00030490 *item;
    int unknown_1a4;
    int key;

    int func_00030490(int key);
};

// Handler 0 of the table at 0x1EC068: 0 when the list at +0x198 already holds `key`; otherwise clears +0x1a4, keeps
// the key at +0x1a8 and a new cleared 16-byte item at +0x1a0, and returns 1.
int Object_000265A0::func_00030490(int key)
{
    for (Entry_00030490 *entry = entries; entry; entry = entry->next) {
        if (entry->key == key)
            return 0;
    }
    unknown_1a4 = 0;
    this->key = key;
    Item_00030490 *item = new Item_00030490;
    this->item = item;
    memset(item, 0, sizeof(Item_00030490));
    return 1;
}
