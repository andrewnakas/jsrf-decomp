struct Item_00031530 {
    int id;
    char unknown_004[0x548];
    Item_00031530 *next;
};

struct Object_00031530 {
    char unknown_000[0x1f0];
    Item_00031530 *head;

    Item_00031530 *func_00031530(int id);
};

Item_00031530 *Object_00031530::func_00031530(int id)
{
    for (Item_00031530 *item = head; item; item = item->next) {
        if (item->id == id) {
            return item;
        }
    }
    return 0;
}
