struct Item_00065730 {
    char unknown_00[0x60];
    Item_00065730 **link;
    Item_00065730 *next;
};

struct Object_00065730 {
    char unknown_00[8];
    Item_00065730 **tail;

    void func_00065730(Item_00065730 *item);
};

// Unlinks an item from the list (links at +0x60/+0x64, tail link at +8) of the object at 0x1FB804 and deletes it.
void Object_00065730::func_00065730(Item_00065730 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
