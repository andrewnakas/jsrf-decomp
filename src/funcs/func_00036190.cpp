struct Object_0006A1B0 {
    int func_0006A1B0(int part);
};

// An entry of the list at +0x1c4: a key, an object, the next entry at +0x10.
struct Item_00036190 {
    int key;
    Object_0006A1B0 *object;
    char unknown_08[0x8];
    Item_00036190 *next;
};

struct Object_000265A0 {
    char unknown_000[0x1c4];
    Item_00036190 *items;

    int func_00036190(int key);
};

// Handler 4 of the table at 0x1EC178: whether part 1 of the object listed under a key at +0x1c4 is complete
// (func_0006A1B0); 0 without one.
int Object_000265A0::func_00036190(int key)
{
    for (Item_00036190 *item = items; item; item = item->next) {
        if (item->key == key) {
            return item->object->func_0006A1B0(1);
        }
    }
    return 0;
}
