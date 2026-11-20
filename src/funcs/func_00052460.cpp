int func_000256C0(unsigned int index, int argument);
void *func_00025700(unsigned int index, int first, int second, int third);

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

struct Block_00052460 {
    int unknown_00;
};

struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0xfe0];
    Block_00052460 *block;
    char unknown_1044[0xc];
    void *unknown_1050;

    void func_00052460();
};

// State handler 10 of the tables at 0x1F9888 and 0x1F9C48: once func_000256C0 (3, the block's +0x0) says so, appends a
// registration of handler 3 with that value to the list at 0x1FA05C, keeps func_00025700 (3, it, 0, 0) at +0x1050 and
// moves to state 0xb.
void Object_0004ABA0::func_00052460()
{
    if (func_000256C0(3, block->unknown_00)) {
        int argument = block->unknown_00;
        Item_0004D8C0 *item = new Item_0004D8C0;
        item->first = 3;
        item->second = argument;
        *data_001FA05C.tail = item;
        item->link = data_001FA05C.tail;
        data_001FA05C.tail = &item->next;
        item->next = 0;
        unknown_1050 = func_00025700(3, block->unknown_00, 0, 0);
        state = 0xb;
    }
}
