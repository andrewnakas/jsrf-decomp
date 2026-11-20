struct Object_0006A1B0 {
    void func_0006A1F0(int part);
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

    void func_000361D0(int key);
};

// Handler 4 of the table at 0x1EC288: runs func_0006A1F0 (part 1) of the object listed under a key at +0x1c4, when
// there is one.
void Object_000265A0::func_000361D0(int key)
{
    for (Item_00036190 *item = items; item; item = item->next) {
        if (item->key == key) {
            if (item->object) {
                item->object->func_0006A1F0(1);
            }
            return;
        }
    }
}
