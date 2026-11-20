struct Item_00030660 {
    int key;
    void *value;
    int unknown_08;
    Item_00030660 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x198];
    Item_00030660 *items;

    void *func_00030660(int key, int skip, int unused);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the value of the item of the list at +0x198 that has this key.
void *Object_000265A0::func_00030660(int key, int skip, int)
{
    for (Item_00030660 *item = items; item; item = item->next) {
        if (item->key == key && !skip) {
            return item->value;
        }
    }
    return 0;
}
