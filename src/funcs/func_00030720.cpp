struct Item_00030720 {
    int key;
    char unknown_04[0x4];
    Item_00030720 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1ac];
    Item_00030720 *items;

    int func_00030720(int key);
};

// Says whether the list at +0x1ac holds an item with this key.
int Object_000265A0::func_00030720(int key)
{
    for (Item_00030720 *item = items; item; item = item->next) {
        if (item->key == key) {
            return 1;
        }
    }
    return 0;
}
