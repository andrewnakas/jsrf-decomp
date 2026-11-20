struct Item_00016200 {
    int unknown_00;
    Item_00016200 *next;
};

struct Object_00016200 {
    char unknown_00[0x8];
    Item_00016200 **tail;

    void func_00016240(Item_00016200 *item);
};

// Appends an item to the third list (tail link at +0x8), as func_00016200 does for the first.
void Object_00016200::func_00016240(Item_00016200 *item)
{
    *tail = item;
    item->next = 0;
    tail = &item->next;
}
