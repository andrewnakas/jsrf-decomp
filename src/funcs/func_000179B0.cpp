struct Entry_000179B0 {
    char unknown_00[0x38];
    int key;
    char unknown_3c[0x58];
    Entry_000179B0 *next;
};

struct Object_0001D920 {
    char unknown_000[0x890];
    Entry_000179B0 *buckets[0x100];

    Entry_000179B0 *func_000179B0(int key);
};

// Finds the entry registered under a key: 256 chains at +0x890 picked by the key's low byte, linked at +0x94.
Entry_000179B0 *Object_0001D920::func_000179B0(int key)
{
    for (Entry_000179B0 *entry = buckets[key & 0xff]; entry; entry = entry->next) {
        if (entry->key == key) {
            return entry;
        }
    }
    return 0;
}
