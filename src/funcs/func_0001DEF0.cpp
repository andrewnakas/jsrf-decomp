struct Item_0001DEF0 {
    char unknown_00[0x30];
    Item_0001DEF0 **link;
    Item_0001DEF0 *next;
};

struct Object_0001DEF0 {
    char unknown_00[0x10];
    Item_0001DEF0 **tail;

    void func_0001DEF0(Item_0001DEF0 *item);
};

// Unlinks an item from the list (links at +0x30/+0x34, tail link at +0x10) of the objects at 0x20CC58 and 0x1EBABC and deletes it.
void Object_0001DEF0::func_0001DEF0(Item_0001DEF0 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
