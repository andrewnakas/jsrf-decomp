struct Item_0001DEA0 {
    char unknown_00[0x84];
    Item_0001DEA0 **link;
    Item_0001DEA0 *next;
};

struct Object_0001DEF0 {
    char unknown_00[0x8];
    Item_0001DEA0 **tail;

    void func_0001DEA0(Item_0001DEA0 *item);
};

// Unlinks an item from the list whose tail link is at +0x8 (links at +0x84/+0x88) and deletes it.
void Object_0001DEF0::func_0001DEA0(Item_0001DEA0 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
