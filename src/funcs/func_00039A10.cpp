struct Item_00039A10 {
    char unknown_00[0x44];
    Item_00039A10 **link;
    Item_00039A10 *next;
};

struct Object_00039A10 {
    char unknown_00[0x10];
    Item_00039A10 **tail;

    Item_00039A10 *func_00039A10();
};

// Appends a new 0x4c-byte item to the list (tail link at +0x10) and returns it.
Item_00039A10 *Object_00039A10::func_00039A10()
{
    Item_00039A10 *item = new Item_00039A10;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
