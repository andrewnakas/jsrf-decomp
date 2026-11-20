// An entry of the hash table at +0x890 (256 chains on the key's low byte, linked at +0x94).
struct Entry_0001B4C0 {
    char unknown_00[0x34];
    int value;
    int key;
    char unknown_3c[0x58];
    Entry_0001B4C0 *next;
};

struct Object_00016200 {
    char unknown_000[0x890];
    Entry_0001B4C0 *chains[256];

    void func_0001B4C0(int key, int value);
};

// Sets the value (+0x34) of the entry with a key, when there is one.
void Object_00016200::func_0001B4C0(int key, int value)
{
    for (Entry_0001B4C0 *entry = chains[key & 0xff]; entry; entry = entry->next) {
        if (entry->key == key) {
            entry->value = value;
            return;
        }
    }
}
