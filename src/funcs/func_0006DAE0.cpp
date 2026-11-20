extern "C" void *memset(void *, int, unsigned int);

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

// Creates an entry under the next key with four values and a word of 1, puts it in its chain and the list, and
// returns its key.
int Object_0006DB80::func_0006DAE0(int first, int second, int third, int fourth)
{
    Entry_0006DB80 *entry = new Entry_0006DB80;
    memset(entry, 0, sizeof(Entry_0006DB80));
    entry->unknown_0c = first;
    entry->key = nextKey;
    nextKey++;
    entry->unknown_18 = third;
    entry->unknown_1c = second;
    entry->unknown_20 = fourth;
    entry->unknown_14 = 1;
    int index = entry->key & 0xff;
    *tails[index] = entry;
    entry->link = tails[index];
    tails[index] = &entry->chain;
    *entryTail = entry;
    entry->link2 = entryTail;
    entryTail = &entry->next;
    return entry->key;
}
