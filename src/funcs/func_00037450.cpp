struct Item_00037450 {
    char unknown_00[0x4];
    int key;
    char unknown_08[0x54];
    Item_00037450 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x15c8];
    Item_00037450 *items;

    int func_00037450(int key);
};

// Says whether the list at +0x15c8 holds an item with this key.
int Object_000265A0::func_00037450(int key)
{
    for (Item_00037450 *item = items; item; item = item->next) {
        if (item->key == key) {
            return 1;
        }
    }
    return 0;
}
