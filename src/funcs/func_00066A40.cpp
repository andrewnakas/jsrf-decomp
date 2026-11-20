struct Item_00066A40 {
    char unknown_00[0x14];
    Item_00066A40 **link;
    Item_00066A40 *next;
};

struct Object_00039A10 {
    char unknown_00[0x10];
    Item_00066A40 **tail;

    Item_00066A40 *func_00066A40();
};

// Appends a new 0x1c-byte item to the list whose tail link is at +0x10 and returns it.
Item_00066A40 *Object_00039A10::func_00066A40()
{
    Item_00066A40 *item = new Item_00066A40;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
