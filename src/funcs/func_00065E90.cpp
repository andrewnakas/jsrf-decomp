struct Item_00039A10 {
    int first;
    int second;
    char unknown_08[0x3c];
    Item_00039A10 **link;
    Item_00039A10 *next;
};

struct Object_00039A10 {
    char unknown_00[0x10];
    Item_00039A10 **tail;

    Item_00039A10 *func_00065E90(int first, int second);
};

// Appends a new 0x4c-byte item holding two words to the list (tail link at +0x10) and returns it.
Item_00039A10 *Object_00039A10::func_00065E90(int first, int second)
{
    Item_00039A10 *item = new Item_00039A10;
    item->first = first;
    item->second = second;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
