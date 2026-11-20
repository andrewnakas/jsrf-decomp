struct Entry_0006DB80 {
    char unknown_00[0x10];
    int key;
    char unknown_14[0x40];
    Entry_0006DB80 *next;
};

struct Object_0006DB80 {
    int unknown_00;
    Entry_0006DB80 *buckets[0x100];

    Entry_0006DB80 *func_0006DB80(int key);
};

// Finds the entry registered under a key: 256 chains picked by the key's low byte, linked at +0x54.
Entry_0006DB80 *Object_0006DB80::func_0006DB80(int key)
{
    for (Entry_0006DB80 *entry = buckets[key & 0xff]; entry; entry = entry->next) {
        if (entry->key == key) {
            return entry;
        }
    }
    return 0;
}
