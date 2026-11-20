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
    char unknown_60[0x20];
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
    void func_00020420(int index, int key, int first, int second);
};

// Kind 5 of the table at 0x1EBD60: when entry `index` holds `key` (+0x80), hands the first value and the entry's
// +0x5c (or 0, 0 when the first is 0) to slot 5 of item 0 of its slot's items, then hands item 0 to slot 6 of item
// 6 + its first level (+0x90, negative levels count as 0), then runs func_000201C0.
void Object_00022990::func_00020420(int index, int key, int first, int second)
{
    State_0001FED0 *list = state;
    Entry_0001FED0 *entry = entries[index];
    if (entry->key == key) {
        int slot = entry->info->slot;
        int levels[3];
        for (int i = 0; i <= 2; i++) {
            levels[i] = entry->levels[i];
            if (levels[i] < 0)
                levels[i] = 0;
        }
        Item_000209B0 *item = list->items[slot]->items[0];
        if (first)
            item->slot5(first, entry->value);
        else
            item->slot5(0, 0);
        list->items[slot]->items[levels[0] + 6]->slot6(item);
        func_000201C0();
    }
}
