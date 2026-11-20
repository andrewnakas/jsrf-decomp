struct Item_000436D0 {
    char unknown_00[0x30];
    int key;
    int unknown_34;
    Item_000436D0 *next;
};

struct Object_000436D0 {
    Item_000436D0 *head;

    Item_000436D0 *func_000436D0(int key);
};

// Finds the item of the list (linked at +0x38) whose key (+0x30) matches, or 0.
Item_000436D0 *Object_000436D0::func_000436D0(int key)
{
    for (Item_000436D0 *item = head; item; item = item->next) {
        if (item->key == key) {
            return item;
        }
    }
    return 0;
}
