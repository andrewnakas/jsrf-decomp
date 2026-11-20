struct Entry_0006DB80 {
    char unknown_00[0x10];
    int key;
    int value;
    char unknown_18[0x3c];
    Entry_0006DB80 *next;
};

struct Object_0006DB80 {
    int unknown_00;
    Entry_0006DB80 *buckets[0x100];

    void func_0006DEB0(int key, int value);
};

// Sets the word at +0x14 of the entry registered under a key, when there is one.
void Object_0006DB80::func_0006DEB0(int key, int value)
{
    for (Entry_0006DB80 *entry = buckets[key & 0xff]; entry; entry = entry->next) {
        if (entry->key == key) {
            entry->value = value;
            return;
        }
    }
}
