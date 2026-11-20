// An entry: in the chain of its key's low byte (linked at +0x4c, back link at +0x50) and in the list whose tail
// link is at +0x808 (linked at +0x54, back link at +0x58). The lookups walk the chains by +0x54.
struct Entry_0006DB80 {
    int unknown_00[3];
    int unknown_0c;
    int key;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    char unknown_24[0x28];
    Entry_0006DB80 *chain;
    Entry_0006DB80 **link;
    Entry_0006DB80 *next;
    Entry_0006DB80 **link2;
};

struct Object_0006DB80 {
    void *vtable;
    Entry_0006DB80 *buckets[0x100];
    Entry_0006DB80 **tails[0x100];
    Entry_0006DB80 *entries;
    Entry_0006DB80 **entryTail;
    char unknown_80c[8];
    int nextKey;

    int func_0006DAE0(int first, int second, int third, int fourth);
    void func_0006DF30(int key);
};

// Unlinks the entry registered under a key from its chain and from the list, and deletes it.
void Object_0006DB80::func_0006DF30(int key)
{
    for (Entry_0006DB80 *entry = buckets[key & 0xff]; entry; entry = entry->next) {
        if (entry->key == key) {
            *entry->link = entry->chain;
            if (entry->chain) {
                entry->chain->link = entry->link;
            } else {
                tails[entry->key & 0xff] = entry->link;
            }
            *entry->link2 = entry->next;
            if (entry->next) {
                entry->next->link2 = entry->link2;
            } else {
                entryTail = entry->link2;
            }
            delete entry;
            return;
        }
    }
}
