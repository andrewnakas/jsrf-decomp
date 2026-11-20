struct Item_00066A70 {
    char unknown_00[0x14];
    Item_00066A70 **link;
    Item_00066A70 *next;
};

struct Object_00039A10 {
    char unknown_00[0x10];
    Item_00066A70 **tail;

    void func_00066A70(Item_00066A70 *item);
};

// Unlinks an item from the list (links at +0x14/+0x18, tail link at +0x10) of the object at 0x1FB8CC and deletes it.
void Object_00039A10::func_00066A70(Item_00066A70 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
