struct Item_00065770 {
    char unknown_00[0x3c];
    Item_00065770 **link;
    Item_00065770 *next;
};

struct Object_00065730 {
    char unknown_00[0x10];
    Item_00065770 **tail;

    Item_00065770 *func_00065770();
};

// Appends a new 0x44-byte item to the list whose tail link is at +0x10 and returns it.
Item_00065770 *Object_00065730::func_00065770()
{
    Item_00065770 *item = new Item_00065770;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
