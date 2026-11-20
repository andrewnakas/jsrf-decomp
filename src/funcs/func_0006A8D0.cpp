// An entry of the draw list (0x10 bytes): the part, its depth, the sort key and the next entry.
struct Item_0006A7C0 {
    void *part;
    float depth;
    unsigned int key;
    Item_0006A7C0 *next;
};

struct Object_0006A720 {
    char unknown_000[0x1c];
    Item_0006A7C0 *items;
    unsigned int count;
    Item_0006A7C0 *head;
    Item_0006A7C0 **tail;
    Item_0006A7C0 *heads[256];
    Item_0006A7C0 **tails[256];

    void func_0006A8D0(int shift);
};

// One pass of a radix sort of the list at +0x24: deals the entries into 256 buckets by the byte of their key at
// `shift` (each bucket keeps its order), then links the buckets back together from the highest to the lowest.
void Object_0006A720::func_0006A8D0(int shift)
{
    for (unsigned int i = 0; i < 256; i++) {
        heads[i] = 0;
        tails[i] = &heads[i];
    }
    Item_0006A7C0 *item = head;
    while (item) {
        unsigned int bucket = (item->key >> shift) & 0xff;
        *tails[bucket] = item;
        Item_0006A7C0 *next = item->next;
        item->next = 0;
        tails[bucket] = &item->next;
        item = next;
    }
    head = 0;
    tail = &head;
    for (int j = 255; j >= 0; j--) {
        if (heads[j]) {
            *tail = heads[j];
            tail = tails[j];
        }
    }
}
