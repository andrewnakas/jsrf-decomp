struct Item_00039A10 {
    char unknown_00[0x44];
    Item_00039A10 **link;
    Item_00039A10 *next;
};

struct Object_00039A10 {
    char unknown_00[0x10];
    Item_00039A10 **tail;

    void func_00039A40(Item_00039A10 *item);
};

// Unlinks an item from the list (links at +0x44/+0x48, tail link at +0x10) of the objects at 0x1EFC74 and 0x1FB820 and deletes it.
void Object_00039A10::func_00039A40(Item_00039A10 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
