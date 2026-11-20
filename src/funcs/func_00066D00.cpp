struct Item_00066D40 {
    char unknown_00[0x40];
    int value;
    int unknown_44;
    int unknown_48;
    int unknown_4c;
    Item_00066D40 **link;
    Item_00066D40 *next;
};

struct Object_00066D40 {
    char unknown_00[0x10];
    Item_00066D40 **tail;

    Item_00066D40 *func_00066D00(int value);
};

// Appends a new 0x58-byte item holding a value to the list (tail link at +0x10) and returns it.
Item_00066D40 *Object_00066D40::func_00066D00(int value)
{
    Item_00066D40 *item = new Item_00066D40;
    item->value = value;
    item->unknown_44 = 0;
    item->unknown_48 = 0;
    item->unknown_4c = 0;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
