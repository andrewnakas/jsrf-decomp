struct Item_000399C0 {
    char unknown_00[0xc4];
    Item_000399C0 **link;
    Item_000399C0 *next;
};

struct Object_00039A10 {
    char unknown_00[0x8];
    Item_000399C0 **tail;

    void func_000399C0(Item_000399C0 *item);
};

// Unlinks an item from the list whose tail link is at +0x8 (links at +0xc4/+0xc8) and deletes it.
void Object_00039A10::func_000399C0(Item_000399C0 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
