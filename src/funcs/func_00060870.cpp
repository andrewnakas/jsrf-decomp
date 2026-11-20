struct Entry_00060870 {
    char unknown_0000[0x30];
    Entry_00060870 *next;
    char unknown_0034[0x13c];
    int key;
    char unknown_0174[0x13b0];
    int owner;
};

struct Object_000607B0 {
    char unknown_00[0x28];
    Entry_00060870 *entries;

    void func_00060810(int key);
    void func_00060870(int owner);
};

// Runs func_00060810 on the key of every entry whose word at +0x1524 matches.
void Object_000607B0::func_00060870(int owner)
{
    Entry_00060870 *entry = entries;
    while (entry) {
        Entry_00060870 *next = entry->next;
        if (entry->owner == owner) {
            func_00060810(entry->key);
        }
        entry = next;
    }
}
