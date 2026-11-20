/* sym: ??0Object_0003E750@@QAE@XZ = 0x0003E690 */
struct Entry_0003E720;

// The object at 0x2314B0 (constructed at 0x18ad85): a hash table of 256 chains with their tail links and two lists.
struct Object_0003E750 {
    Object_0003E750();
    virtual ~Object_0003E750()
    {
    }

    int unknown_04;
    Entry_0003E720 *buckets[0x100];
    Entry_0003E720 **tails[0x100];
    Entry_0003E720 *entries;
    Entry_0003E720 **entryTail;
    Entry_0003E720 *others;
    Entry_0003E720 **otherTail;
};

Object_0003E750::Object_0003E750()
{
    unknown_04 = 1;
    for (int i = 0; i < 0x100; i++) {
        buckets[i] = 0;
        tails[i] = &buckets[i];
    }
    entries = 0;
    entryTail = &entries;
    others = 0;
    otherTail = &others;
}
