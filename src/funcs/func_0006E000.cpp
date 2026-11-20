/* sym: ??0Object_0006E130@@QAE@XZ = 0x0006E000 */
/* const: 0x10000 */
void __cdecl operator delete(void *memory);
void *__cdecl operator new(unsigned int size);

// An entry of the table (0x18 bytes).
struct Entry_0006E130 {
    int id;
    int count;
    int value;
    Entry_0006E130 **link;
    Entry_0006E130 *next;
    Entry_0006E130 *nextFree;
};

// The object at 0x252790 (constructed at 0x18AF50; table 0x1CC61C): 0x400 entries from a pool, kept free in a list
// (+8/+0xc) or registered under ids in a hash table of 256 chains, 500 value slots and the current ids of two tables.
struct Object_0006E130 {
    Object_0006E130();
    virtual ~Object_0006E130()
    {
        operator delete(pool);
    }

    Entry_0006E130 *pool;
    Entry_0006E130 *freeHead;
    Entry_0006E130 *freeTail;
    int freeCount;
    Entry_0006E130 *buckets[0x100];
    Entry_0006E130 **tails[0x100];
    int used[500];
    int current0;
    int current1;
    int ids0[10];
    int ids1[10];
    unsigned int counter;
};

// Chains the 0x400 pool entries into the free list, clears the table, the value slots and the current ids (-1) and
// starts the ids at 0x10000.
Object_0006E130::Object_0006E130()
{
    Entry_0006E130 *entries = (Entry_0006E130 *)operator new(0x400 * sizeof(Entry_0006E130));
    pool = entries;
    for (unsigned int i = 0; i < 0x400; i++) {
        entries[i].nextFree = &entries[i + 1];
    }
    freeHead = entries;
    freeTail = &entries[0x3ff];
    freeTail->nextFree = 0;
    freeCount = 0x400;
    for (unsigned int j = 0; j < 0x100; j++) {
        buckets[j] = 0;
        tails[j] = &buckets[j];
    }
    for (unsigned int k = 0; k < 500; k++) {
        used[k] = 0;
    }
    current0 = 0;
    current1 = 0;
    for (unsigned int m = 0; m < 10; m++) {
        ids0[m] = -1;
        ids1[m] = -1;
    }
    counter = 0x10000;
}
