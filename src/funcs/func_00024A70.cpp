struct Item_00024A70 {
    char unknown_00[0x28];
    Item_00024A70 **link;
    Item_00024A70 *next;
};

struct Object_00024A70 {
    char unknown_00[8];
    Item_00024A70 **tail;

    void func_00024A70(Item_00024A70 *item);
};

// Unlinks an item from the list (links at +0x28/+0x2c, tail link at +8) of the object at 0x1EC050 and deletes it.
void Object_00024A70::func_00024A70(Item_00024A70 *item)
{
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
