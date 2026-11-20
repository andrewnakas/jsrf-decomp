// An object of the state's lists at +0x9c: slot 5 takes two values.
struct Item_000209B0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    char unknown_04[0x20];
    unsigned int flags;
    char unknown_28[0x30];
    float scale;
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
    char unknown_0c[0x50];
    int value;
    char unknown_60[0x20];
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
    void func_000203A0(int index, int key, int first, int second);
};

// Kind 10 of the table at 0x1EBD60: when entry `index` holds `key` (+0x80), sets flag
// 0x10 and scale 1 of item 0 of its slot's items and hands the first value and the entry's
// +0x5c (or 0, 0 when the first is 0) to its slot 5, then runs func_000201C0.
void Object_00022990::func_000203A0(int index, int key, int first, int second)
{
    Entry_0001FED0 *entry = entries[index];
    if (entry->key == key) {
        Item_000209B0 *item = state->items[entry->info->slot]->items[0];
        item->flags |= 0x10;
        item->scale = 1.0f;
        if (first)
            item->slot5(first, entry->value);
        else
            item->slot5(0, 0);
        func_000201C0();
    }
}
