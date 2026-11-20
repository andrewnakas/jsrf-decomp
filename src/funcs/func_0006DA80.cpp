/* sym: ??0Object_0006DB80@@QAE@XZ = 0x0006DA80 */
struct Entry_0006DB80;
struct Item_0006DEE0;

// The object at 0x251F78 (constructed at 0x18af35; table 0x1CC618): a hash table of 256 chains with their tail
// links and two lists.
struct Object_0006DB80 {
    Object_0006DB80();
    virtual ~Object_0006DB80()
    {
    }

    Entry_0006DB80 *buckets[0x100];
    Entry_0006DB80 **tails[0x100];
    Entry_0006DB80 *entries;
    Entry_0006DB80 **entryTail;
    Item_0006DEE0 *items;
    Item_0006DEE0 **itemTail;
    int unknown_814;
};

Object_0006DB80::Object_0006DB80()
{
    entries = 0;
    entryTail = &entries;
    for (int i = 0; i < 0x100; i++) {
        buckets[i] = 0;
        tails[i] = &buckets[i];
    }
    items = 0;
    itemTail = &items;
    unknown_814 = 1;
}
