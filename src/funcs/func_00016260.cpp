struct Item_00016260 {
    int unknown_00;
    int value;
    char unknown_08[0x18];
    int unknown_20[8];
    Item_00016260 *next;
};

struct Object_00016200 {
    char unknown_00[0xc];
    Item_00016260 **tail;

    void func_00016260(Item_00016260 *item, int value);
};

// Appends an item to the fourth list (tail link at +0xc), with a value at +0x4 and its words +0x20 to +0x3c cleared.
void Object_00016200::func_00016260(Item_00016260 *item, int value)
{
    *tail = item;
    item->unknown_20[0] = 0;
    item->unknown_20[1] = 0;
    item->unknown_20[2] = 0;
    item->unknown_20[3] = 0;
    item->unknown_20[4] = 0;
    item->unknown_20[5] = 0;
    item->unknown_20[6] = 0;
    item->unknown_20[7] = 0;
    item->value = value;
    item->next = 0;
    tail = &item->next;
}
