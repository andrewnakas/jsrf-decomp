struct Item_000162A0 {
    char unknown_00[0xc];
    Item_000162A0 *head;
    Item_000162A0 **tail;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    Item_000162A0 *next;
};

struct Object_00016200 {
    char unknown_00[0x28];
    Item_000162A0 **tail;

    void func_00016320(Item_000162A0 *item);
};

// Appends an item to the seventh list (tail link at +0x28) and empties the item's own list (+0xc).
void Object_00016200::func_00016320(Item_000162A0 *item)
{
    *tail = item;
    item->next = 0;
    tail = &item->next;
    item->head = 0;
    item->tail = &item->head;
    item->unknown_14 = 0;
    item->unknown_18 = 0;
    item->unknown_1c = 0;
}
