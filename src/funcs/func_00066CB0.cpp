struct Data_00066CB0 {
    int unknown_00;
};

struct Item_00066CB0 {
    Data_00066CB0 *data;
    int unknown_04[2];
    Item_00066CB0 **link;
    Item_00066CB0 *next;
};

struct Object_00065730 {
    char unknown_00[8];
    Item_00066CB0 **tail;

    void func_00066CB0(Item_00066CB0 *item);
};

// Deletes an item's data, unlinks the item from the list whose tail link is at +0x8 (links at +0xc/+0x10) and
// deletes it.
void Object_00065730::func_00066CB0(Item_00066CB0 *item)
{
    delete item->data;
    *item->link = item->next;
    if (item->next) {
        item->next->link = item->link;
    } else {
        tail = item->link;
    }
    delete item;
}
