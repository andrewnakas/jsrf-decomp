struct Item_000657A0 {
    char unknown_00[0x3c];
    Item_000657A0 **link;
    Item_000657A0 *next;
};

struct Object_00065730 {
    char unknown_00[0x10];
    Item_000657A0 **tail;

    void func_000657A0(Item_000657A0 *item);
};

// Unlinks an item from the list (links at +0x3c/+0x40, tail link at +0x10) of the object at 0x1FB804 and deletes it.
void Object_00065730::func_000657A0(Item_000657A0 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
