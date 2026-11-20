struct Entry_0003E720 {
    char unknown_00[0x9c];
    int key;
    char unknown_a0[0x64];
    Entry_0003E720 *next;
};

struct Object_0003E750 {
    void *vtable;
    int unknown_04;
    Entry_0003E720 *buckets[0x100];

    Entry_0003E720 *func_0003E720(int key);
};

// Finds the entry registered under a key: 256 chains picked by the key's low byte.
Entry_0003E720 *Object_0003E750::func_0003E720(int key)
{
    for (Entry_0003E720 *entry = buckets[key & 0xff]; entry; entry = entry->next) {
        if (entry->key == key) {
            return entry;
        }
    }
    return 0;
}
