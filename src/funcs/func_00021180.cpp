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
    Item_000209B0 *items[2];
};

struct Info_0001FED0 {
    int unknown_00;
    int slot;
};

struct Entry_0001FED0 {
    char unknown_00[8];
    Info_0001FED0 *info;
    char unknown_0c[0x74];
    int key;
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
    void func_00021180(int index, int key, int first, int second);
};

// Kind 9 of the table at 0x1EBD60: when entry `index` holds `key` (+0x80), hands the two values (or 0, 0 when the
// first is 0) to slot 5 of item 0 of its slot's items,
// hands that item to slot 6 of item 1 and runs func_000201C0.
void Object_00022990::func_00021180(int index, int key, int first, int second)
{
    Entry_0001FED0 *entry = entries[index];
    State_0001FED0 *state = this->state;
    if (entry->key == key) {
        int slot = entry->info->slot;
        Item_000209B0 *item = state->items[slot]->items[0];
        if (first)
            item->slot5(first, second);
        else
            item->slot5(0, 0);
        state->items[slot]->items[1]->slot6(item);
        func_000201C0();
    }
}
