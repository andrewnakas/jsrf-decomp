struct Item_00033B70 {
    int key;
    char unknown_04[0x28];
    Item_00033B70 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1658];
    Item_00033B70 *items;

    int func_00033B70(int key);
};

// Says whether the list at +0x1658 holds an item with this key.
int Object_000265A0::func_00033B70(int key)
{
    for (Item_00033B70 *item = items; item; item = item->next) {
        if (item->key == key) {
            return 1;
        }
    }
    return 0;
}
