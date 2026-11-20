struct Item_0001DCF0 {
    char unknown_00[0x20];
    Item_0001DCF0 **link;
    Item_0001DCF0 *next;
};

struct Object_00039A10 {
    char unknown_00[0x10];
    Item_0001DCF0 **tail;

    void func_0001DD20(Item_0001DCF0 *item);
};

// Unlinks an item from the list (links at +0x20/+0x24, tail link at +0x10) of the object at 0x1EBAA8 and deletes it.
void Object_00039A10::func_0001DD20(Item_0001DCF0 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
