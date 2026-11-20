struct Item_00065E50 {
    char unknown_00[8];
    void *data;
    char unknown_0c[4];
    Item_00065E50 **link;
    Item_00065E50 *next;
};

struct Object_00039A10 {
    char unknown_00[8];
    Item_00065E50 **tail;

    void func_00065E50(Item_00065E50 *item);
};

// Unlinks an item from the other list of the object at 0x1FB820 (links at +0x10/+0x14, tail link at +0x8) and
// deletes its data and itself.
void Object_00039A10::func_00065E50(Item_00065E50 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item->data;
    delete item;
}
