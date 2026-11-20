struct Item_0006DEE0 {
    char unknown_00[0x68];
    Item_0006DEE0 *next;
};

struct Object_0006DB80 {
    char unknown_000[0x810];
    Item_0006DEE0 **itemTail;

    void func_0006DEE0(Item_0006DEE0 *item);
};

// Appends an item to the list whose tail link is at +0x810 (linked at +0x68).
void Object_0006DB80::func_0006DEE0(Item_0006DEE0 *item)
{
    if (item) {
        *itemTail = item;
        itemTail = &item->next;
        item->next = 0;
    }
}
