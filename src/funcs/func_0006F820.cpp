struct Item_0006F820 {
    char unknown_00[0x6c];
    Item_0006F820 **link;
    Item_0006F820 *next;
};

struct Object_0001DEF0 {
    char unknown_00[8];
    Item_0006F820 **tail;

    void func_0006F820(Item_0006F820 *item);
};

// Unlinks an item from the list (links at +0x6c/+0x70, tail link at +8) of the object at 0x20CC58 and deletes it.
void Object_0001DEF0::func_0006F820(Item_0006F820 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
