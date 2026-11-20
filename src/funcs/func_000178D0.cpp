struct Vector3 {
    float x;
    float y;
    float z;
};

// An item of the hash table at +0x84 (chains by the key's low byte, linked at +0x64 with a back link at +0x60) and
// of the list whose tail link is at +0x888 (linked at +0x6c, back link at +0x68).
struct Item_00017940 {
    struct Record {
        int value;
        Vector3 position;
        int extra;
    };

    int unknown_00;
    int key;
    int unknown_08;
    Record records[4];
    unsigned int count;
    Item_00017940 **link;
    Item_00017940 *next;
    Item_00017940 **link2;
    Item_00017940 *next2;
};

struct Object_00016200 {
    char unknown_000[0x84];
    Item_00017940 *buckets[0x100];
    Item_00017940 **tails[0x100];
    char unknown_884[4];
    Item_00017940 **tail2;

    void func_000178D0(Item_00017940 *item);
};

// Unlinks an item from its chain and from the second list, then deletes it.
void Object_00016200::func_000178D0(Item_00017940 *item)
{
    if (item) {
        if (item->link) {
            *item->link = item->next;
            if (item->next) {
                item->next->link = item->link;
            } else {
                tails[item->key & 0xff] = item->link;
            }
        }
        if (item->link2) {
            *item->link2 = item->next2;
            if (item->next2) {
                item->next2->link2 = item->link2;
            } else {
                tail2 = item->link2;
            }
        }
        delete item;
    }
}
