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
    char unknown_0000[0x44];
    int unknown_44;
    int unknown_48;
    char unknown_004c[0xc];
    int unknown_58;
    int state;
    char unknown_0060[0xfe0];
    Block_00052460 *block;
    char unknown_1044[8];
    int unknown_104c;

    void func_000520D0();
};

// State handler 1 of the tables at 0x1F9888 and 0x1F9C48: once func_000256C0 (0, +0x58) says so, appends a registration
// of handler 0 with +0x58 to the list at 0x1FA05C, keeps func_00025700 (0, +0x58, 0, 0) at +0x1040 and its first word
// at +0x104c, 1 into +0x48 and moves to state 2 (with +0x44 set) or 3.
void Object_0004ABA0::func_000520D0()
{
    if (func_000256C0(0, unknown_58)) {
        int argument = unknown_58;
        Item_0004D8C0 *item = new Item_0004D8C0;
        item->first = 0;
        item->second = argument;
        *data_001FA05C.tail = item;
        item->link = data_001FA05C.tail;
        data_001FA05C.tail = &item->next;
        item->next = 0;
        block = (Block_00052460 *)func_00025700(0, unknown_58, 0, 0);
        unknown_104c = block->unknown_00;
        unknown_48 = 1;
        state = unknown_44 ? 2 : 3;
    }
}
