struct Item_00066A00 {
    void *data;
    int unknown_04;
    Item_00066A00 **link;
    Item_00066A00 *next;
};

struct Object_00039A10 {
    char unknown_00[8];
    Item_00066A00 **tail;

    void func_00066A00(Item_00066A00 *item);
};

// Unlinks an item from the list whose tail link is at +0x8 (links at +0x8/+0xc), deletes its data and the item.
void Object_00039A10::func_00066A00(Item_00066A00 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    if (item->data) {
        operator delete(item->data);
    }
    delete item;
}
