struct Item_0001DCF0 {
    char unknown_00[0x20];
    Item_0001DCF0 **link;
    Item_0001DCF0 *next;
};

struct Object_00039A10 {
    char unknown_00[0x10];
    Item_0001DCF0 **tail;

    Item_0001DCF0 *func_0001DCF0();
};

// Appends a new 0x28-byte item to the list (tail link at +0x10) and returns it.
Item_0001DCF0 *Object_00039A10::func_0001DCF0()
{
    Item_0001DCF0 *item = new Item_0001DCF0;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
