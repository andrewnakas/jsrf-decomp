struct Item_00035590 {
    int key;
    char unknown_04[0x30];
    Item_00035590 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1680];
    Item_00035590 *items;

    int func_00035590(int key);
};

// Says whether the list at +0x1680 holds an item with this key.
int Object_000265A0::func_00035590(int key)
{
    for (Item_00035590 *item = items; item; item = item->next) {
        if (item->key == key) {
            return 1;
        }
    }
    return 0;
}
