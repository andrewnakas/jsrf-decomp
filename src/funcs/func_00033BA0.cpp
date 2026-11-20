struct Item_00033BA0 {
    int key;
    char unknown_04[0x18];
    void *values[3];
    int unknown_28;
    Item_00033BA0 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1658];
    Item_00033BA0 *items;

    void *func_00033BA0(int key, int unused, int index);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): one of the three values of the item of the list at +0x1658 that has this key.
void *Object_000265A0::func_00033BA0(int key, int, int index)
{
    for (Item_00033BA0 *item = items; item; item = item->next) {
        if (item->key == key && (unsigned int)index < 3) {
            return item->values[index];
        }
    }
    return 0;
}
