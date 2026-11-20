struct Item_00066D40 {
    char unknown_00[0x50];
    Item_00066D40 **link;
    Item_00066D40 *next;
};

struct Object_00065730 {
    char unknown_00[0x10];
    Item_00066D40 **tail;

    void func_00066D40(Item_00066D40 *item);
};

// Unlinks an item from the list (links at +0x50/+0x54, tail link at +0x10) of the object at 0x1FB8E8 and deletes it.
void Object_00065730::func_00066D40(Item_00066D40 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
