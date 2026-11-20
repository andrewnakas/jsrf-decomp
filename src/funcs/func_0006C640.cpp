struct Item_0006C640 {
    char unknown_00[0x10];
    int unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    int unknown_24;
    int unknown_28;
    int unknown_2c;
    int unknown_30;
    Item_0006C640 *next;
};

struct Object_000149B0 {
    int unknown_00;
    void *entries;
    char unknown_08[8];
    Item_0006C640 **tail;

    void func_0006C640(Item_0006C640 *item, int first, int second, int third, int fourth);
};

// Appends the item to the list whose last link +0x10 points at, with the four values and its counters cleared.
void Object_000149B0::func_0006C640(Item_0006C640 *item, int first, int second, int third, int fourth)
{
    *tail = item;
    tail = &item->next;
    item->unknown_10 = 0;
    item->unknown_24 = fourth;
    item->unknown_28 = first;
    item->unknown_30 = second;
    item->unknown_2c = third;
    item->unknown_18 = 0;
    item->unknown_1c = 0;
    item->unknown_20 = 0;
    item->next = 0;
}
