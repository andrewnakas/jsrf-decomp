extern "C" void *memset(void *destination, int value, unsigned int size);

// A 0x660-byte entry of the list at +0x1e4.
struct Entry_00031490 {
    int unknown_000;
    int used;
    int key;
    char unknown_00c[0x650];
    Entry_00031490 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1e4];
    Entry_00031490 *entries;
    char unknown_01e8[4];
    Entry_00031490 *entry;
    char unknown_01f0[0x6c];
    int unknown_25c;
    int key;

    int func_00031490(int key);
};

// Handler 2 of the table at 0x1EC068: when the list at +0x1e4 holds `key`, marks that entry used and returns 0;
// otherwise clears +0x25c, keeps the key at +0x260 and a new cleared, used entry at +0x1ec, and returns 1.
int Object_000265A0::func_00031490(int key)
{
    for (Entry_00031490 *item = entries; item; item = item->next) {
        if (item->key == key) {
            item->used = 1;
            return 0;
        }
    }
    unknown_25c = 0;
    this->key = key;
    entry = new Entry_00031490;
    memset(entry, 0, sizeof(Entry_00031490));
    entry->used = 1;
    return 1;
}
