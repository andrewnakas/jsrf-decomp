// An entry of the hash table at +0x890 (chains by the key's low byte, linked at +0x94).
struct Entry_000179B0 {
    struct Record {
        int words[5];
    };

    char unknown_00[0x38];
    int key;
    Record records[4];
    unsigned int count;
    int unknown_90;
    Entry_000179B0 *next;
};

struct Object_00016200 {
    char unknown_000[0x890];
    Entry_000179B0 *buckets[0x100];

    void func_000179E0(int key, int first, int second, int third, int fourth, int fifth);
};

// Adds a record of five words to the entry registered under a key, up to four.
void Object_00016200::func_000179E0(int key, int first, int second, int third, int fourth, int fifth)
{
    for (Entry_000179B0 *entry = buckets[key & 0xff]; entry; entry = entry->next) {
        if (entry->key == key) {
            if (entry->count < 4) {
                Entry_000179B0::Record *record = &entry->records[entry->count];
                record->words[0] = first;
                record->words[1] = second;
                record->words[2] = third;
                record->words[3] = fourth;
                record->words[4] = fifth;
                entry->count++;
            }
            return;
        }
    }
}
