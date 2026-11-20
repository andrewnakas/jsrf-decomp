// An object of the state's lists at +0x9c: slot 5 takes two values.
struct Item_000209B0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
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
    char unknown_00[0x80];
    int *active;
    char unknown_84[0x18];
    Items_000209B0 **items;
    Item_000209B0 **others;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990); 0x21320 runs the member-pointer table at 0x1EBD60
// by each entry's kind.
struct Object_00022990 {
    char unknown_00[0xdc];
    State_0001FED0 *state;
    Entry_0001FED0 **entries;

    void func_00020670(int index, unsigned int message, int first, int second);
};

// Kind 13 of the table at 0x1EBD60: for message 8, hands the two values (or 0, 0 when the first is 0) to slot 5 of
// item 0 of entry `index`'s slot's items; for messages 0xf and 0x10, 0, 0 to slot 5 of the slot's other item (+0xa0)
// when the slot is active (+0x80) and has one.
void Object_00022990::func_00020670(int index, unsigned int message, int first, int second)
{
    State_0001FED0 *state = this->state;
    int slot = entries[index]->info->slot;
    Item_000209B0 *item = state->items[slot]->items[0];
    switch (message) {
    case 8:
        if (first)
            item->slot5(first, second);
        else
            item->slot5(0, 0);
        break;
    case 0xf:
    case 0x10:
        if (state->active[slot] && state->others[slot])
            state->others[slot]->slot5(0, 0);
        break;
    }
}
