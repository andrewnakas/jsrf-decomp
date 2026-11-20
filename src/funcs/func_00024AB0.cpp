struct Item_00024AB0 {
    char unknown_00[0x30];
    Item_00024AB0 **link;
    Item_00024AB0 *next;
    int unknown_38;
    char unknown_3c[0x2c];
};

struct Object_00024A70 {
    char unknown_00[0x10];
    Item_00024AB0 **tail;

    Item_00024AB0 *func_00024AB0();
};

// Appends a new 0x68-byte item to the list whose tail link is at +0x10, its word at +0x38 clear, and returns it.
Item_00024AB0 *Object_00024A70::func_00024AB0()
{
    Item_00024AB0 *item = new Item_00024AB0;
    item->unknown_38 = 0;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
