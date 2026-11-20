// An entry of the list at +0x1724: its id first, the next entry at +0x3c.
struct Item_0002C2A0 {
    int id;
    char unknown_04[0x38];
    Item_0002C2A0 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1724];
    Item_0002C2A0 *items;
    char unknown_1728[0x20];
    int unknown_1748;

    int func_0002C2A0(int id);
};

// Handler 18 of the table at 0x1EC178: 1 when the list at +0x1724 holds an entry with the id, unless the word at
// +0x1748 is set; else 0.
int Object_000265A0::func_0002C2A0(int id)
{
    Item_0002C2A0 *item = items;
    if (!unknown_1748) {
        for (; item; item = item->next) {
            if (item->id == id) {
                return 1;
            }
        }
    }
    return 0;
}
