struct Item_000360E0 {
    int key;
    void *value;
    char unknown_08[8];
    Item_000360E0 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1c4];
    Item_000360E0 *items;

    void *func_000360E0(int key, int unused1, int unused2);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the value of the item of the list at +0x1c4 that has this key.
void *Object_000265A0::func_000360E0(int key, int, int)
{
    for (Item_000360E0 *item = items; item; item = item->next) {
        if (item->key == key) {
            return item->value;
        }
    }
    return 0;
}
