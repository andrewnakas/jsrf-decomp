struct Item_0001DCA0 {
    char unknown_00[0xa0];
    Item_0001DCA0 **link;
    Item_0001DCA0 *next;
};

struct Object_00066AB0 {
    char unknown_00[0x8];
    Item_0001DCA0 **tail;

    void func_0001DCA0(Item_0001DCA0 *item);
};

// Unlinks an item from the list whose tail link is at +0x8 (links at +0xa0/+0xa4) and deletes it.
void Object_00066AB0::func_0001DCA0(Item_0001DCA0 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
