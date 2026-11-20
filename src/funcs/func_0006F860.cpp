struct Item_0006F860 {
    char unknown_00[0x30];
    Item_0006F860 **link;
    Item_0006F860 *next;
    int unknown_38;
    char unknown_3c[0xc];
};

struct Object_0001DEF0 {
    char unknown_00[0x10];
    Item_0006F860 **tail;

    Item_0006F860 *func_0006F860();
};

// Appends a new 0x48-byte item to the list whose tail link is at +0x10, its word at +0x38 clear, and returns it.
Item_0006F860 *Object_0001DEF0::func_0006F860()
{
    Item_0006F860 *item = new Item_0006F860;
    item->unknown_38 = 0;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
