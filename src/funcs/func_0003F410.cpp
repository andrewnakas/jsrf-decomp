struct Entry_0003E720 {
    char unknown_00[0x9c];
    int key;
    int unknown_a0;
    char unknown_a4[0x60];
    Entry_0003E720 *next;
};

struct Object_0003E750 {
    void *vtable;
    int unknown_04;
    Entry_0003E720 *buckets[0x100];

    void func_0003F410(int key, int value);
};

// Stores a value at +0xa0 of the entry registered under a key, when there is one.
void Object_0003E750::func_0003F410(int key, int value)
{
    for (Entry_0003E720 *entry = buckets[key & 0xff]; entry; entry = entry->next) {
        if (entry->key == key) {
            entry->unknown_a0 = value;
            return;
        }
    }
}
