struct Item_00030630 {
    int key;
    char unknown_04[0x8];
    Item_00030630 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x198];
    Item_00030630 *items;

    int func_00030630(int key);
};

// Says whether the list at +0x198 holds an item with this key.
int Object_000265A0::func_00030630(int key)
{
    for (Item_00030630 *item = items; item; item = item->next) {
        if (item->key == key) {
            return 1;
        }
    }
    return 0;
}
