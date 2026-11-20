// An object of the state's lists at +0x9c: slot 5 takes two values.
struct Item_000209B0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
    virtual void slot6(Item_000209B0 *item);
};

struct Items_000209B0 {
    Item_000209B0 *items[10];
};

struct Info_0001FED0 {
    int unknown_00;
    int slot;
};

struct Entry_0001FED0 {
    char unknown_00[8];
    Info_0001FED0 *info;
    char unknown_0c[0x50];
    int value;
    char unknown_60[0x1c];
    int lead;
    int key;
    char unknown_84[0xc];
    int levels[3];
};

struct State_0001FED0 {
    char unknown_00[0x9c];
    Items_000209B0 **items;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990); 0x21320 runs the member-pointer table at 0x1EBD60
// by each entry's kind.
struct Object_00022990 {
    char unknown_00[0xdc];
    State_0001FED0 *state;
    Entry_0001FED0 **entries;

    void func_000201C0();
    void func_00020570(int index, int key, int first, int second);
};

// Kind 3 of the table at 0x1EBD60: when entry `index` holds `key` (+0x80), hands the two values (or 0, 0 when the
// first is 0) to slot 5 of item 0 of its slot's items, then item 0 to slot 6 of items 1, 5 and 9 moved on by the
// entry's three levels (+0x90, negative ones count as 0; level 3 of the first picks item 3 or, when +0x7c is not
// positive, item 4), then runs func_000201C0.
void Object_00022990::func_00020570(int index, int key, int first, int second)
{
    State_0001FED0 *list = state;
    Entry_0001FED0 *entry = entries[index];
    if (entry->key == key) {
        int slot = entry->info->slot;
        Item_000209B0 *item = list->items[slot]->items[0];
        if (first)
            item->slot5(first, second);
        else
            item->slot5(0, 0);
        int levels[3];
        for (int i = 0; i <= 2; i++) {
            levels[i] = entry->levels[i];
            if (levels[i] < 0)
                levels[i] = 0;
        }
        if (levels[0] == 3) {
            int next = (entry->lead <= 0) + 3;
            list->items[slot]->items[next]->slot6(item);
        } else {
            list->items[slot]->items[levels[0] + 1]->slot6(item);
        }
        list->items[slot]->items[levels[1] + 5]->slot6(item);
        list->items[slot]->items[levels[2] + 9]->slot6(item);
        func_000201C0();
    }
}
