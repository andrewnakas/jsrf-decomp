struct Item_00031500 {
    char unknown_00[0x8];
    int key;
    char unknown_0c[0x650];
    Item_00031500 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1e4];
    Item_00031500 *items;

    int func_00031500(int key);
};

// Says whether the list at +0x1e4 holds an item with this key.
int Object_000265A0::func_00031500(int key)
{
    for (Item_00031500 *item = items; item; item = item->next) {
        if (item->key == key) {
            return 1;
        }
    }
    return 0;
}
