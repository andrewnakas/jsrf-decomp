extern "C" void *memset(void *destination, int value, unsigned int size);

struct Entry_00036050 {
    int key;
    char unknown_04[0xc];
    Entry_00036050 *next;
};

struct Item_00036050 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
};

struct Object_000265A0 {
    char unknown_0000[0x1c4];
    Entry_00036050 *entries;
    char unknown_01c8[4];
    Item_00036050 *item;
    int unknown_1d0;
    int key;

    int func_00036050(int key);
};

// Handler 3 of the table at 0x1EC068: 0 when the list at +0x1c4 already holds `key`; otherwise clears +0x1d0, keeps
// the key at +0x1d4 and a new cleared 20-byte item at +0x1cc, and returns 1.
int Object_000265A0::func_00036050(int key)
{
    for (Entry_00036050 *entry = entries; entry; entry = entry->next) {
        if (entry->key == key)
            return 0;
    }
    unknown_1d0 = 0;
    this->key = key;
    Item_00036050 *item = new Item_00036050;
    this->item = item;
    memset(item, 0, sizeof(Item_00036050));
    return 1;
}
