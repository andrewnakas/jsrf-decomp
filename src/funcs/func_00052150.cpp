int func_000256C0(unsigned int index, int argument);

// A registration: a handler index and its argument, released through func_00025740.
struct Item_0004D8C0 {
    int first;
    int second;
    Item_0004D8C0 *next;
    Item_0004D8C0 **link;
};

struct Object_0004D8C0 {
    int unknown_00;
    Item_0004D8C0 *items;
    Item_0004D8C0 **tail;
};

extern Object_0004D8C0 data_001FA05C;

struct Object_0004ABA0 {
    char unknown_000[0x58];
    int unknown_58;
    int state;

    void func_00052150();
};

// State handler 4 of the table at 0x1F9888: once func_000256C0 (0x1d, +0x58) says so, appends a registration of
// handler 0x1d with +0x58 to the list at 0x1FA05C (released by its func_0004D900) and moves to state 5.
void Object_0004ABA0::func_00052150()
{
    if (func_000256C0(0x1d, unknown_58)) {
        int argument = unknown_58;
        Item_0004D8C0 *item = new Item_0004D8C0;
        item->second = argument;
        item->first = 0x1d;
        *data_001FA05C.tail = item;
        item->link = data_001FA05C.tail;
        data_001FA05C.tail = &item->next;
        item->next = 0;
        state = 5;
    }
}
