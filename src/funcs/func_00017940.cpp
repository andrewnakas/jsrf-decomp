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

    void func_00017940(int key, int value, const Vector3 *position, int extra);
};

// Adds a record (a value, a position and another value) to the item registered under a key, up to four.
void Object_00016200::func_00017940(int key, int value, const Vector3 *position, int extra)
{
    for (Item_00017940 *item = buckets[key & 0xff]; item; item = item->next) {
        if (item->key == key) {
            if (item->count < 4) {
                Item_00017940::Record *record = &item->records[item->count];
                record->value = value;
                record->position = *position;
                record->extra = extra;
                item->count++;
            }
            return;
        }
    }
}
